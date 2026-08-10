"""

╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗
║  ██████╗   ██████╗  ██████╗   ██████╗  ██████╗  ███████╗  ██████╗   █████╗  ███████╗ ██╗   ██╗ ███████╗  ║
║  ██╔══██╗ ██╔═══██╗ ██╔══██╗ ██╔═══██╗ ██╔══██╗ ██╔════╝ ██╔════╝  ██╔══██╗ ██╔════╝ ██║   ██║ ██╔════╝  ║
║  ██████╔╝ ██║   ██║ ██████╔╝ ██║   ██║ ██████╔╝ █████╗   ██║  ███╗ ███████║ ███████╗ ██║   ██║ ███████╗  ║
║  ██╔══██╗ ██║   ██║ ██╔══██╗ ██║   ██║ ██╔═══╝  ██╔══╝   ██║   ██║ ██╔══██║ ╚════██║ ██║   ██║ ╚════██║  ║
║  ██║  ██║ ╚██████╔╝ ██████╔╝ ╚██████╔╝ ██║      ███████╗ ╚██████╔╝ ██║  ██║ ███████║ ╚██████╔╝ ███████║  ║
║  ╚═╝  ╚═╝  ╚═════╝  ╚═════╝   ╚═════╝  ╚═╝      ╚══════╝  ╚═════╝  ╚═╝  ╚═╝ ╚══════╝  ╚═════╝  ╚══════╝  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝                                                                                              
   Autonomous Robot Vision System | Pillar Detection & Navigation
   ──────────────────────────────────────────────────────────────
    
    🎯 Advanced Computer Vision for Obstacle Course Navigation
    🚀 Real-time HSV Color Classification & Morphological Processing
    🧠 Intelligent Pillar Configuration Analysis
    ⚡ High-Performance Arduino Communication Interface
    
    Copyright © 2026 RoboPegasus Team | Autonomous Robotics Division

"""    
import serial
import numpy as np
import time
from picamera2 import Picamera2
import cv2 as cv2

# Minimum area thresholds for pillar detection
RED_PILLAR_MIN_AREA = 1700
GREEN_PILLAR_MIN_AREA = 2100

# Global variables for navigation state
navigation_mode = None
initial_pillar_detected = False

def initialize_camera_system():
    """
    Configure and initialize the camera with optimized settings for pillar detection.
    Returns configured camera instance.
    """
    cam = Picamera2()
    camera_config = cam.create_preview_configuration()
    camera_config['main']['format'] = 'RGB888'
    cam.configure(camera_config)
    cam.start()
    cam.set_controls({"AfMode": 1, "LensPosition": 425, "AwbEnable": False})
    return cam

def establish_arduino_connection(port_name='/dev/ttyACM0', baud_rate=115200):
    """
    Establish serial communication with Arduino controller.
    Sends initialization signal and waits for confirmation.
    """
    arduino_link = serial.Serial(port_name, baud_rate, timeout=1)
    arduino_link.flush()
    time.sleep(3.5)
    arduino_link.write("S#".encode('ascii'))
    print("Setup response:", arduino_link.readline().decode().strip())
    return arduino_link

def generate_corner_exclusion_mask(frame_dimensions, exclusion_size=(50, 50)):
    """
    Create a mask to exclude corner regions from pillar detection.
    This prevents false detections from corner artifacts.
    """
    height, width, _ = frame_dimensions
    mask = np.ones((height, width), dtype=np.uint8) * 255
    
    # Exclude top-left corner
    mask[0:exclusion_size[1], 0:exclusion_size[0]] = 0
    
    # Exclude top-right corner  
    x_right = width - exclusion_size[0]
    mask[0:exclusion_size[1], x_right:width] = 0
    
    return mask

def transmit_pillar_information(arduino_connection, pillar_data):
    """
    Send pillar detection results to Arduino controller.
    Appends termination character and handles response.
    """
    message = pillar_data + '#'
    arduino_connection.write(message.encode('ascii'))
    time.sleep(0.1)
    print(arduino_connection.readline())

def extract_pillar_features(color_mask, area_threshold, pillar_type):
    """
    Extract pillar features from color-filtered mask.
    Returns list of detected pillars with their properties.
    """
    # Apply morphological operations to reduce noise
    morphology_kernel = np.ones((5, 5), np.uint8)
    filtered_mask = cv2.morphologyEx(color_mask, cv2.MORPH_OPEN, morphology_kernel)
    filtered_mask = cv2.morphologyEx(filtered_mask, cv2.MORPH_CLOSE, morphology_kernel)

    # Find contours in the processed mask
    contour_list, _ = cv2.findContours(filtered_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    pillar_objects = []
    for contour in contour_list:
        contour_area = cv2.contourArea(contour)
        
        if contour_area > area_threshold:
            # Calculate centroid coordinates
            moments = cv2.moments(contour)         
            center_x = int(moments["m10"] / moments["m00"])
            
            pillar_objects.append({
                'color': pillar_type,
                'cx': center_x,
                'area': contour_area
            })
    
    return pillar_objects

def process_color_detection(frame_data, red_range_1, red_range_2, green_range):
    """
    Apply color filtering to detect red and green pillars in the frame.
    Returns detected pillar objects and visualization masks.
    """
    hsv_converted = cv2.cvtColor(frame_data, cv2.COLOR_RGB2HSV)
    
    # Create color masks for red and green pillars
    red_mask_lower = cv2.inRange(hsv_converted, *red_range_1)
    red_mask_upper = cv2.inRange(hsv_converted, *red_range_2)
    red_combined_mask = cv2.bitwise_xor(red_mask_lower, red_mask_upper)
    green_mask = cv2.inRange(hsv_converted, *green_range)

    # Extract pillar features from masks
    red_pillars = extract_pillar_features(red_combined_mask, min_area=200, pillar_type='R')
    green_pillars = extract_pillar_features(green_mask, min_area=300, pillar_type='G')
    
    return red_pillars, green_pillars, red_combined_mask, green_mask

def analyze_standard_pillar_configuration(red_detections, green_detections, nav_direction):
    """
    Analyze pillar configuration for standard navigation scenarios.
    Implements complex logic for multi-pillar environments.
    """
    combined_pillars = red_detections + green_detections
    
    if not combined_pillars:
        return 'NN'
    
    # Handle three-pillar scenarios by removing edge pillars
    if len(combined_pillars) == 3:
        # Sort by horizontal position
        combined_pillars.sort(key=lambda pillar: pillar['cx'])
        
        if nav_direction == 'CCW':
            # Remove leftmost pillar for counter-clockwise navigation
            combined_pillars = combined_pillars[1:]
        elif nav_direction == 'CW':
            # Remove rightmost pillar for clockwise navigation
            combined_pillars = combined_pillars[:-1]
    
    # Sort remaining pillars by area (largest first)
    combined_pillars.sort(key=lambda pillar: pillar['area'], reverse=True)
    
    # Determine final pillar selection based on area and count
    if len(combined_pillars) == 2:
        # Select the two largest pillars
        selected_pillars = combined_pillars[:2]
    elif len(combined_pillars) == 1:
        # Single pillar detected
        selected_pillars = combined_pillars
    else:
        return 'NN'
    
    # Generate color sequence string
    if len(selected_pillars) == 2:
        color_sequence = selected_pillars[0]['color'] + selected_pillars[1]['color']
    else:
        # Duplicate single pillar color
        color_sequence = selected_pillars[0]['color'] + selected_pillars[0]['color']
    
    return color_sequence

def analyze_initial_pillar_detection(red_detections, green_detections, nav_direction):
    """
    Simplified analysis for initial pillar detection phase.
    Returns duplicated color of the largest detected pillar.
    """
    combined_pillars = red_detections + green_detections
    
    if not combined_pillars:
        return 'NN'
    
    # Sort by area and select the largest pillar
    combined_pillars.sort(key=lambda pillar: pillar['area'], reverse=True)
    primary_pillar = combined_pillars[0]
    
    # Return duplicated color of primary pillar
    return primary_pillar['color'] + primary_pillar['color']

def execute_main_control_loop():
    """
    Main execution loop for pillar detection system.
    Handles camera initialization, Arduino communication, and pillar analysis.
    """
    global navigation_mode
    global initial_pillar_detected
    
    # Initialize system components
    camera_system = initialize_camera_system()
    arduino_connection = establish_arduino_connection()

    # Define HSV color ranges for pillar detection
    red_hsv_range_1 = ((120, 150, 120), (179, 255, 255))
    red_hsv_range_2 = ((130, 150, 120), (179, 255, 255))
    green_hsv_range = ((15, 15, 50), (50, 255, 255))

    try:
        while True:
            # Check for incoming Arduino commands
            if arduino_connection.in_waiting > 0:
                received_command = arduino_connection.readline().decode().strip()
               
                # Handle navigation mode commands
                if received_command in ['CCW', 'CW']:
                    navigation_mode = received_command
                    print(f"Navigation mode set: {navigation_mode}")
                
                # Handle capture commands for standard navigation
                elif received_command == 'C' and navigation_mode is not None and initial_pillar_detected:
                    current_frame = camera_system.capture_array()

                    # Apply corner exclusion mask
                    corner_mask = generate_corner_exclusion_mask(current_frame.shape, exclusion_size=(100, 70))
                    masked_frame = cv2.bitwise_and(current_frame, current_frame, mask=corner_mask)

                    # Detect pillars in the frame
                    red_detections, green_detections, _, _ = process_color_detection(
                        masked_frame, red_hsv_range_1, red_hsv_range_2, green_hsv_range
                    )

                    # Analyze pillar configuration
                    pillar_result = analyze_standard_pillar_configuration(red_detections, green_detections, navigation_mode)
                    transmit_pillar_information(arduino_connection, pillar_result)

                # Handle capture commands for initial pillar detection
                elif received_command == 'C' and navigation_mode is not None and not initial_pillar_detected:
                    current_frame = camera_system.capture_array()

                    # Apply corner exclusion mask
                    corner_mask = generate_corner_exclusion_mask(current_frame.shape, exclusion_size=(100, 70))
                    masked_frame = cv2.bitwise_and(current_frame, current_frame, mask=corner_mask)

                    # Detect pillars in the frame
                    red_detections, green_detections, _, _ = process_color_detection(
                        masked_frame, red_hsv_range_1, red_hsv_range_2, green_hsv_range
                    )

                    # Analyze initial pillar configuration
                    pillar_result = analyze_initial_pillar_detection(red_detections, green_detections, navigation_mode)
                    initial_pillar_detected = True
                    transmit_pillar_information(arduino_connection, pillar_result)

    finally:
        # Cleanup system resources
        camera_system.stop()
        arduino_connection.close()
        print("System shutdown complete")

if __name__ == "__main__":
    execute_main_control_loop()