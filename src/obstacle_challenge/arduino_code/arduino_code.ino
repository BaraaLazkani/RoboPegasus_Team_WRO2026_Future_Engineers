/*

  ╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║  ██████╗   ██████╗  ██████╗   ██████╗  ██████╗  ███████╗  ██████╗   █████╗  ███████╗ ██╗   ██╗ ███████╗  ║
  ║  ██╔══██╗ ██╔═══██╗ ██╔══██╗ ██╔═══██╗ ██╔══██╗ ██╔════╝ ██╔════╝  ██╔══██╗ ██╔════╝ ██║   ██║ ██╔════╝  ║
  ║  ██████╔╝ ██║   ██║ ██████╔╝ ██║   ██║ ██████╔╝ █████╗   ██║  ███╗ ███████║ ███████╗ ██║   ██║ ███████╗  ║
  ║  ██╔══██╗ ██║   ██║ ██╔══██╗ ██║   ██║ ██╔═══╝  ██╔══╝   ██║   ██║ ██╔══██║ ╚════██║ ██║   ██║ ╚════██║  ║
  ║  ██║  ██║ ╚██████╔╝ ██████╔╝ ╚██████╔╝ ██║      ███████╗ ╚██████╔╝ ██║  ██║ ███████║ ╚██████╔╝ ███████║  ║
  ║  ╚═╝  ╚═╝  ╚═════╝  ╚═════╝   ╚═════╝  ╚═╝      ╚══════╝  ╚═════╝  ╚═╝  ╚═╝ ╚══════╝  ╚═════╝  ╚══════╝  ║
  ╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    Autonomous Robot Navigation System | Arduino Mega Controller
    ─────────────────────────────────────────────────────────────

    🎯 Multi-Sensor Fusion Navigation & Obstacle Avoidance
    🚀 Advanced PID Control with IMU Integration
    🧠 Intelligent Wall Following & Autonomous Turning
    ⚡ Real-time Ultrasonic Array Processing

    Hardware: Arduino Mega, MPU6050, 7x Ultrasonic Sensors, Servo Motors
    Copyright © 2026 RoboPegasus Team | Autonomous Robotics Division

*/

#include <Servo.h>
#include <NewPing.h>
#include "Wire.h"
#include <MPU6050_light.h>
#include <ArduinoQueue.h>

// ============================================================================
// HARDWARE PIN DEFINITIONS
// ============================================================================

// Ultrasonic Sensor Pin Assignments
#define FRONT_TRIG_PIN 25
#define FRONT_ECHO_PIN 24
#define RIGHT_SIDE_TRIG_PIN 53
#define RIGHT_SIDE_ECHO_PIN 52
#define RIGHT_BACK_TRIG_PIN 23
#define RIGHT_BACK_ECHO_PIN 22
#define LEFT_SIDE_TRIG_PIN 12
#define LEFT_SIDE_ECHO_PIN 13
#define LEFT_BACK_TRIG_PIN 51
#define LEFT_BACK_ECHO_PIN 50
#define BACK_RIGHT_TRIG_PIN 29
#define BACK_RIGHT_ECHO_PIN 28
#define BACK_LEFT_TRIG_PIN 49
#define BACK_LEFT_ECHO_PIN 48

// Motor Control Pins
#define RIGHT_MOTOR_PWM 10
#define LEFT_MOTOR_PWM 9

// ============================================================================
// GLOBAL CONSTANTS AND CONFIGURATION
// ============================================================================

// Sensor Configuration
const int ULTRASONIC_MAX_DISTANCE = 300;
const int SENSOR_FILTER_SIZE = 7;
const double SOUND_VELOCITY_CM_US = 0.0343;

// Navigation Parameters
const int STEERING_CENTER_POSITION = 93;
const int LEFT_CENTER_POSITION = 90;
const int RIGHT_CENTER_POSITION = 80;
const int MAX_STEERING_ANGLE = STEERING_CENTER_POSITION + 35;
const int MIN_STEERING_ANGLE = STEERING_CENTER_POSITION - 50;
const int RIGHT_TURN_ANGLE = 40;
const int LEFT_TURN_ANGLE = -55;

// Speed Control Settings
const int NAVIGATION_SPEED = 60;
const int TURNING_SPEED = 60;
const int SAFETY_SPEED = 35;
const int WALL_FOLLOWING_DISTANCE = 15;

// PID Control Parameters
const float MPU_PROPORTIONAL_GAIN = 1.2;
const float MPU_DERIVATIVE_GAIN = 1.0;
const float MAXIMUM_ANGLE_CORRECTION = 0.27;

// ============================================================================
// SENSOR ARRAY DEFINITIONS
// ============================================================================

// Sensor ID Enumeration
enum SensorID {
  FRONT_SENSOR = 0,
  RIGHT_SIDE_SENSOR = 1,
  RIGHT_BACK_SENSOR = 2,
  BACK_RIGHT_SENSOR = 3,
  BACK_LEFT_SIDE_SENSOR = 4,
  LEFT_BACK_SENSOR = 5,
  LEFT_SIDE_SENSOR = 6
};

// Pin Arrays for Sensor Initialization
int ultrasonic_echo_pins[7] = {
  FRONT_ECHO_PIN, RIGHT_SIDE_ECHO_PIN, RIGHT_BACK_ECHO_PIN,
  BACK_RIGHT_ECHO_PIN, BACK_LEFT_ECHO_PIN, LEFT_BACK_ECHO_PIN, LEFT_SIDE_ECHO_PIN
};

int ultrasonic_trigger_pins[7] = {
  FRONT_TRIG_PIN, RIGHT_SIDE_TRIG_PIN, RIGHT_BACK_TRIG_PIN,
  BACK_RIGHT_TRIG_PIN, BACK_LEFT_TRIG_PIN, LEFT_BACK_TRIG_PIN, LEFT_SIDE_TRIG_PIN
};

// ============================================================================
// HARDWARE OBJECTS AND GLOBAL VARIABLES
// ============================================================================

// Servo Motor Objects
Servo steering_servo;
Servo left_gripper_servo;
Servo right_gripper_servo;

// IMU Object
MPU6050 inertial_measurement_unit(Wire);

// Ultrasonic Sensor Array
NewPing ultrasonic_sensors[7] = {
  NewPing(ultrasonic_trigger_pins[0], ultrasonic_echo_pins[0], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[1], ultrasonic_echo_pins[1], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[2], ultrasonic_echo_pins[2], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[3], ultrasonic_echo_pins[3], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[4], ultrasonic_echo_pins[4], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[5], ultrasonic_echo_pins[5], ULTRASONIC_MAX_DISTANCE),
  NewPing(ultrasonic_trigger_pins[6], ultrasonic_echo_pins[6], ULTRASONIC_MAX_DISTANCE)
};

// ============================================================================
// SENSOR FILTERING SYSTEM
// ============================================================================

// Moving Average Filter Queues
ArduinoQueue<double> front_sensor_filter;
ArduinoQueue<double> right_side_filter;
ArduinoQueue<double> right_back_filter;
ArduinoQueue<double> left_side_filter;
ArduinoQueue<double> left_back_filter;
ArduinoQueue<double> back_left_filter;
ArduinoQueue<double> back_right_filter;

// Filtered Sensor Readings
double filtered_front_distance = 0;
double filtered_right_side_distance = 0;
double filtered_right_back_distance = 0;
double filtered_left_side_distance = 0;
double filtered_left_back_distance = 0;
double filtered_back_left_distance = 0;
double filtered_back_right_distance = 0;

// ============================================================================
// NAVIGATION STATE VARIABLES
// ============================================================================

// Turn Execution Flags
bool right_turn_completed = false;
bool left_turn_completed = false;
int total_turn_count = 0;

// Orientation Control
int imu_reference_angle = 0;
double target_steering_angle = 0;
double orientation_error = 0;
double ultrasonic_wall_error = 0;

// ============================================================================
// PILLAR COLORS VARIABLES
// ============================================================================

char colors[8] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'}; // array to store the pillars
int current_pillar = 0; // pointer for the current pillar
String data = "NN"; // variable to store current two pillars

// Timing Control
long system_delay_timer;

// ============================================================================
// SENSOR DATA ACQUISITION FUNCTIONS
// ============================================================================

/**
   Apply moving average filter to sensor readings for noise reduction
   @param current_reading: Latest sensor measurement
   @param filtered_mean: Reference to filtered value storage
   @param filter_queue: Moving average queue for this sensor
   @return: Filtered sensor value
*/
double apply_sensor_filter(double current_reading, double &filtered_mean, ArduinoQueue<double> &filter_queue) {
  if (filter_queue.isEmpty()) {
    // Initialize filter with current reading
    filtered_mean = current_reading;
    for (int i = 0; i < SENSOR_FILTER_SIZE; i++) {
      filter_queue.enqueue(current_reading);
    }
  } else {
    // Update moving average
    double oldest_value = filter_queue.dequeue();
    filtered_mean -= (oldest_value / SENSOR_FILTER_SIZE);
    filtered_mean += (current_reading / SENSOR_FILTER_SIZE);
    filter_queue.enqueue(current_reading);
  }
  return filtered_mean;
}

/**
   Get filtered distance measurement from front ultrasonic sensor
   @return: Filtered distance in centimeters
*/
double measure_front_distance() {
  double pulse_duration = ultrasonic_sensors[FRONT_SENSOR].ping();
  double raw_distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (raw_distance == 0) raw_distance = ULTRASONIC_MAX_DISTANCE;

  return apply_sensor_filter(raw_distance, filtered_front_distance, front_sensor_filter);
}

/**
   Get filtered distance measurement from right side ultrasonic sensor
   @return: Filtered distance in centimeters
*/
double measure_right_side_distance() {
  double pulse_duration = ultrasonic_sensors[RIGHT_SIDE_SENSOR].ping();
  double raw_distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (raw_distance == 0) raw_distance = ULTRASONIC_MAX_DISTANCE;

  return apply_sensor_filter(raw_distance, filtered_right_side_distance, right_side_filter);
}

/**
   Get filtered distance measurement from left side ultrasonic sensor
   @return: Filtered distance in centimeters
*/
double measure_left_side_distance() {
  double pulse_duration = ultrasonic_sensors[LEFT_SIDE_SENSOR].ping();
  double raw_distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (raw_distance == 0) raw_distance = ULTRASONIC_MAX_DISTANCE;

  return apply_sensor_filter(raw_distance, filtered_left_side_distance, left_side_filter);
}

/**
   Get filtered distance measurement from back left ultrasonic sensor
   @return: Filtered distance in centimeters
*/
double measure_back_left_distance() {
  double pulse_duration = ultrasonic_sensors[BACK_LEFT_SIDE_SENSOR].ping();
  double raw_distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (raw_distance == 0) raw_distance = ULTRASONIC_MAX_DISTANCE;

  return apply_sensor_filter(raw_distance, filtered_back_left_distance, back_left_filter);
}

/**
   Get filtered distance measurement from back right ultrasonic sensor
   @return: Filtered distance in centimeters
*/
double measure_back_right_distance() {
  double pulse_duration = ultrasonic_sensors[BACK_RIGHT_SENSOR].ping();
  double raw_distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (raw_distance == 0) raw_distance = ULTRASONIC_MAX_DISTANCE;

  return apply_sensor_filter(raw_distance, filtered_back_right_distance, back_right_filter);
}

/**
   Get unfiltered distance measurement for quick obstacle detection
   @param sensor_id: ID of the sensor to read
   @return: Raw distance measurement in centimeters
*/
double get_instant_distance(int sensor_id) {
  double pulse_duration = ultrasonic_sensors[sensor_id].ping();
  double distance = (pulse_duration / 2) * SOUND_VELOCITY_CM_US;

  if (distance == 0) distance = ULTRASONIC_MAX_DISTANCE;

  return distance;
}

/**
   Reset all sensor filters to clear accumulated data
*/
void reset_sensor_filters() {
  for (int i = 0; i < SENSOR_FILTER_SIZE; i++) {
    if (!front_sensor_filter.isEmpty()) front_sensor_filter.dequeue();
    if (!right_side_filter.isEmpty()) right_side_filter.dequeue();
    if (!right_back_filter.isEmpty()) right_back_filter.dequeue();
    if (!left_side_filter.isEmpty()) left_side_filter.dequeue();
    if (!left_back_filter.isEmpty()) left_back_filter.dequeue();
    if (!back_left_filter.isEmpty()) back_left_filter.dequeue();
    if (!back_right_filter.isEmpty()) back_right_filter.dequeue();
  }
}

// ============================================================================
// MOTOR CONTROL FUNCTIONS
// ============================================================================

/**
   Drive robot forward at specified speed
   @param speed_percentage: Motor speed as percentage (0-100)
*/
void drive_forward(int speed_percentage) {
  int pwm_value = speed_percentage * 254 / 100;
  analogWrite(LEFT_MOTOR_PWM, 0);
  analogWrite(RIGHT_MOTOR_PWM, pwm_value);
}

/**
   Drive robot backward at specified speed
   @param speed_percentage: Motor speed as percentage (0-100)
*/
void drive_backward(int speed_percentage) {
  int pwm_value = speed_percentage * 254 / 100;
  analogWrite(RIGHT_MOTOR_PWM, 0);
  analogWrite(LEFT_MOTOR_PWM, pwm_value);
}

/**
   Stop all motor movement
*/
void stop_motors() {
  analogWrite(RIGHT_MOTOR_PWM, 0);
  analogWrite(LEFT_MOTOR_PWM, 0);
}

// ============================================================================
// TIMING AND DELAY FUNCTIONS
// ============================================================================

/**
   Non-blocking delay that maintains IMU updates
   @param delay_milliseconds: Duration to delay in milliseconds
*/
void maintain_imu_during_delay(int delay_milliseconds) {
  system_delay_timer = millis();
  while (millis() - system_delay_timer < delay_milliseconds) {
    inertial_measurement_unit.update();
  }
}

// ============================================================================
// PID CONTROL FUNCTIONS
// ============================================================================

/**
   PID control for maintaining orientation during backward movement
*/
void backward_orientation_control() {
  orientation_error = inertial_measurement_unit.getAngleZ() - imu_reference_angle;
  target_steering_angle = STEERING_CENTER_POSITION + (MPU_PROPORTIONAL_GAIN * orientation_error);

  // Apply steering limits
  if (target_steering_angle > MAX_STEERING_ANGLE) target_steering_angle = MAX_STEERING_ANGLE;
  if (target_steering_angle < MIN_STEERING_ANGLE) target_steering_angle = MIN_STEERING_ANGLE;

  steering_servo.write(target_steering_angle);
}

/**
   PID control for maintaining orientation during forward movement
*/
void forward_orientation_control() {
  orientation_error = inertial_measurement_unit.getAngleZ() - imu_reference_angle;
  target_steering_angle = STEERING_CENTER_POSITION - (MPU_PROPORTIONAL_GAIN * orientation_error);

  // Apply steering limits
  if (target_steering_angle > MAX_STEERING_ANGLE) target_steering_angle = MAX_STEERING_ANGLE;
  if (target_steering_angle < MIN_STEERING_ANGLE) target_steering_angle = MIN_STEERING_ANGLE;

  steering_servo.write(target_steering_angle);
}

/**
   PID control for maintaining orientations of servos that holds ultrasonic sensors during movement
*/

void servo_ultra_pid() {
  float error = inertial_measurement_unit.getAngleZ() - imu_reference_angle;
  delay(10);
  if (error > 80) {
    left_gripper_servo.write(LEFT_CENTER_POSITION - 80);
    right_gripper_servo.write(RIGHT_CENTER_POSITION - 80);
  }
  else if (error < -80) {
    left_gripper_servo.write(LEFT_CENTER_POSITION + 80);
    right_gripper_servo.write(RIGHT_CENTER_POSITION + 80);
  }
  else {
    left_gripper_servo.write(LEFT_CENTER_POSITION - error);
    right_gripper_servo.write(RIGHT_CENTER_POSITION - error);
  }
}
/**
   Wall following control for left side obstacles
   @param wall_distance: Current distance to left wall
*/
void maintain_left_wall_distance(double wall_distance) {
  if (wall_distance < WALL_FOLLOWING_DISTANCE) {
    ultrasonic_wall_error = WALL_FOLLOWING_DISTANCE - wall_distance;
    steering_servo.write(STEERING_CENTER_POSITION + 1.2 * ultrasonic_wall_error);
    maintain_imu_during_delay(10);
  }
}

/**
   Wall following control for right side obstacles
   @param wall_distance: Current distance to right wall
*/
void maintain_right_wall_distance(double wall_distance) {
  if (wall_distance < WALL_FOLLOWING_DISTANCE) {
    ultrasonic_wall_error = WALL_FOLLOWING_DISTANCE - wall_distance;
    steering_servo.write(STEERING_CENTER_POSITION - 1.2 * ultrasonic_wall_error);
    maintain_imu_during_delay(10);
  }
}

// ============================================================================
// NAVIGATION MANEUVER FUNCTIONS
// ============================================================================

/**
   Execute 90-degree right turn maneuver
*/
void execute_right_turn() {
  // Prevent multiple consecutive turns
  if (right_turn_completed && total_turn_count != 0) return;

  maintain_imu_during_delay(30);

  // Handle front obstacle during turn initiation
  if (get_instant_distance(FRONT_SENSOR) < 35) {
    stop_motors();
    maintain_imu_during_delay(30);

    // Back away from obstacle
    while (get_instant_distance(FRONT_SENSOR) < 40) {
      drive_backward(SAFETY_SPEED);
      backward_orientation_control();
      maintain_imu_during_delay(30);
    }

    stop_motors();
    maintain_imu_during_delay(20);
    drive_forward(SAFETY_SPEED);
    maintain_imu_during_delay(250);
  }

  // Execute turning sequence
  steering_servo.write(STEERING_CENTER_POSITION + RIGHT_TURN_ANGLE);
  drive_forward(TURNING_SPEED);
  inertial_measurement_unit.update();

  // Turn until 70-degree rotation achieved
  while (inertial_measurement_unit.getAngleZ() < imu_reference_angle + 70) {
    inertial_measurement_unit.update();
  }

  // Update reference angle and complete turn
  imu_reference_angle += 90;
  stop_motors();
  maintain_imu_during_delay(50);
  steering_servo.write(STEERING_CENTER_POSITION);
  maintain_imu_during_delay(50);

  // Resume navigation
  drive_forward(NAVIGATION_SPEED);
  inertial_measurement_unit.update();
  forward_orientation_control();
  reset_sensor_filters();

  right_turn_completed = true;
  total_turn_count++;
  maintain_imu_during_delay(30);

  // Navigate until clear of turn area
  while (measure_back_left_distance() < 110 && measure_back_right_distance() < 110) {
    maintain_imu_during_delay(30);
    maintain_right_wall_distance(measure_right_side_distance());
    maintain_left_wall_distance(measure_left_side_distance());
    maintain_imu_during_delay(30);

    if (measure_right_side_distance() > WALL_FOLLOWING_DISTANCE &&
        measure_left_side_distance() > WALL_FOLLOWING_DISTANCE) {
      forward_orientation_control();
    }
  }
}

/**
   Execute 90-degree left turn maneuver
*/
void execute_left_turn() {
  // Prevent multiple consecutive turns
  if (left_turn_completed && total_turn_count != 0) return;

  maintain_imu_during_delay(30);

  // Handle front obstacle during turn initiation
  if (get_instant_distance(FRONT_SENSOR) < 35) {
    stop_motors();
    maintain_imu_during_delay(30);

    // Back away from obstacle
    while (get_instant_distance(FRONT_SENSOR) < 40) {
      drive_backward(SAFETY_SPEED);
      backward_orientation_control();
      maintain_imu_during_delay(30);
    }

    stop_motors();
    maintain_imu_during_delay(20);
    drive_forward(SAFETY_SPEED);
    maintain_imu_during_delay(250);
  }

  // Execute turning sequence
  steering_servo.write(STEERING_CENTER_POSITION + LEFT_TURN_ANGLE);
  drive_forward(TURNING_SPEED);
  inertial_measurement_unit.update();

  // Turn until 70-degree rotation achieved
  while (inertial_measurement_unit.getAngleZ() > imu_reference_angle - 70) {
    inertial_measurement_unit.update();
  }

  // Update reference angle and complete turn
  imu_reference_angle -= 90;
  stop_motors();
  maintain_imu_during_delay(50);
  steering_servo.write(STEERING_CENTER_POSITION);
  maintain_imu_during_delay(50);

  // Resume navigation
  drive_forward(NAVIGATION_SPEED);
  inertial_measurement_unit.update();
  forward_orientation_control();
  reset_sensor_filters();

  left_turn_completed = true;
  total_turn_count++;
  maintain_imu_during_delay(30);

  // Navigate until clear of turn area
  while (measure_back_left_distance() < 110 && measure_back_right_distance() < 110) {
    maintain_imu_during_delay(30);
    maintain_right_wall_distance(measure_right_side_distance());
    maintain_left_wall_distance(measure_left_side_distance());
    maintain_imu_during_delay(30);

    if (measure_right_side_distance() > WALL_FOLLOWING_DISTANCE &&
        measure_left_side_distance() > WALL_FOLLOWING_DISTANCE) {
      forward_orientation_control();
    }
  }
}



// ============================================================================
// READING PILLARS' COLORS FUNCTION
// ============================================================================

void READ_PILLAR_COLOR() {
  stop_motors(); // stop the motor so the camera can take a clear frame
  delay(3000);
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('#'); // take the data recived from raspberry pi through Serial connection
    Serial.println(data);
    // Store the data in the pillar colors array
    colors[current_pillar] = data[0];
    colors[current_pillar + 1] = data[1];
  }

}

// ============================================================================
// PASSING PILLARS FUNCTIONS
// ============================================================================
void pass_red_pillar()
{
  if (get_instant_distance(RIGHT_SIDE_SENSOR) > 50) // IF THE ROBOT IS FAR FROM THE PILLAR, DO A RIGHT TURN TO BECOME CLOSER
  {
    steering_servo.write(STEERING_CENTER_POSITION + 35); // TURN THE SERVO RIGHT
    delay(100);
    while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle + 30)
    { drive_forward(65);
      delay(30);
      servo_ultra_pid();
      if (get_instant_distance(RIGHT_SIDE_SENSOR) < 25)
        break;
    }
    stop_motors();
    steering_servo.write(STEERING_CENTER_POSITION);
    delay(100);
    while ( get_instant_distance(RIGHT_SIDE_SENSOR) > 25) // MOVE FORWARD TO BE CLOSER TO THE WALL
    { delay(30);
      drive_forward(65);
    }
    stop_motors();
    steering_servo.write(STEERING_CENTER_POSITION - 50); // AFTER THE ROBOT BECOMES CLOSE TO THE PILLAR DO LEFT TURN TO BECOME STRAIGHT
    delay(150);
    drive_forward(65);
    while ( inertial_measurement_unit.getAngleZ() > imu_reference_angle + 15)
    {
      servo_ultra_pid();
      delay(30);
    }
  }

  else // IF THE ROBOT WAS CLOSE TO THE PILLAR SIDE, PASS IT IMMEDIATLY
  {
    long t = millis();
    while (millis() - t < 2000)
    {
      inertial_measurement_unit.update();
      forward_orientation_control();
      servo_ultra_pid();
    }
  }
}

void pass_green_pillar()
{ if (get_instant_distance(LEFT_SIDE_SENSOR) > 50) // IF THE ROBOT IS FAR FROM THE PILLAR, DO A RIGHT TURN TO BECOME CLOSER
  {
    steering_servo.write(STEERING_CENTER_POSITION - 35); // TURN THE SERVO LEFT
    delay(100);
    while ( inertial_measurement_unit.getAngleZ() > imu_reference_angle - 30)
    { drive_forward(65);
      delay(30);
      servo_ultra_pid();
      if (get_instant_distance(LEFT_SIDE_SENSOR) < 25)
        break;
    }
    stop_motors();
    steering_servo.write(STEERING_CENTER_POSITION);
    delay(100);
    while ( get_instant_distance(LEFT_SIDE_SENSOR) > 25) // MOVE FORWARD TO BE CLOSER TO THE WALL
    { delay(30);
      drive_forward(65);
    }
    stop_motors();
    steering_servo.write(STEERING_CENTER_POSITION + 35); // AFTER THE ROBOT BECOMES CLOSE TO THE PILLAR DO LEFT TURN TO BECOME STRAIGHT
    delay(150);
    drive_forward(65);
    while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle - 15)
    {
      servo_ultra_pid();
      delay(30);
    }
  }

  else // IF THE ROBOT WAS CLOSE TO THE PILLAR SIDE, PASS IT IMMEDIATLY
  {
    long t = millis();
    while (millis() - t < 2000)
    {
      inertial_measurement_unit.update();
      forward_orientation_control();
      servo_ultra_pid();
    }
  }
}

// ============================================================================
// START FUNCTIONS
// ============================================================================

void startup_cw() // going out from the parking lot in clockwise direction
{

  steering_servo.write(STEERING_CENTER_POSITION  + 40);// TURN RIGHT TO GO OUT FROM THE PARKING LOT
  delay(300);
  drive_forward(50);
  while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle + 75)
  {
    inertial_measurement_unit.update();
  }

  stop_motors();
  steering_servo.write(STEERING_CENTER_POSITION);
  delay(100);
  drive_forward(50);
  while ( get_instant_distance(FRONT_SENSOR) > 30) // Move the motor forward until the robot becomes close to the inner wall
  {
    delay(30);
  }
  stop_motors();
  delay(30);


  steering_servo.write(STEERING_CENTER_POSITION + 40); // do back turn so the robot can see the first pillar
  delay(300);
  drive_backward(45);
  while ( inertial_measurement_unit.getAngleZ() > imu_reference_angle + 10)
  {
    inertial_measurement_unit.update();
  }

  stop_motors();
  delay(100);
  READ_PILLAR_COLOR(); // read the first pillar data and pass pillar depending on the data
  char c = data[0];
  Serial.print(c);
  if (c == 'R') pass_red_pillar();
  else pass_green_pillar();
  execute_right_turn();
}


void startup_ccw() // going out from the parking lot in counterclockwise direction
{

  steering_servo.write(STEERING_CENTER_POSITION  - 40);// TURN LEFT TO GO OUT FROM THE PARKING LOT
  delay(300);
  drive_forward(50);
  while ( inertial_measurement_unit.getAngleZ() > imu_reference_angle - 75)
  {
    inertial_measurement_unit.update();
  }

  stop_motors();
  steering_servo.write(STEERING_CENTER_POSITION);
  delay(100);
  drive_forward(50);
  while ( get_instant_distance(FRONT_SENSOR) > 30) // Move the motor forward until the robot becomes close to the inner wall
  {
    delay(30);
  }
  stop_motors();
  delay(30);


  steering_servo.write(STEERING_CENTER_POSITION - 40); // do back turn so the robot can see the first pillar
  delay(300);
  drive_backward(45);
  while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle - 10)
  {
    inertial_measurement_unit.update();
  }

  stop_motors();
  delay(100);
  READ_PILLAR_COLOR(); // read the first pillar data and pass pillar depending on the data
  char c = data[0];
  Serial.print(c);
  if (c == 'R') pass_red_pillar();
  else pass_green_pillar();
  execute_left_turn();
}


// ============================================================================
// PARKING FUNCTIONS
// ============================================================================

void PARKING_CW() {
  steering_servo.write(STEERING_CENTER_POSITION);
  drive_forward(25);

  // walk slowly  until finding the parking lot
  while (get_instant_distance(LEFT_SIDE_SENSOR) > 20)
  {
    inertial_measurement_unit.update();
    forward_orientation_control();
    servo_ultra_pid();
  }
  stop_motors();

  // enter to the parking lot
  steering_servo.write(STEERING_CENTER_POSITION - 40);
  delay(100);
  drive_forward(35);
  while ( inertial_measurement_unit.getAngleZ() > imu_reference_angle - 30)
  {
    inertial_measurement_unit.update();
    servo_ultra_pid();
  }
  stop_motors();
  steering_servo.write(STEERING_CENTER_POSITION + 20);
  delay(100);
  while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle )
  {
    inertial_measurement_unit.update();
    servo_ultra_pid();
  }

  // repeat until the left sensor reads small distance which means that the robot is completly inside the parking lot

  while (get_instant_distance(LEFT_SIDE_SENSOR) > 3.5)
  {

    // do a left turn to become closer to the wall

    steering_servo.write(STEERING_CENTER_POSITION - 25);
    delay(100);
    drive_forward(35);
    while ( get_instant_distance(FRONT_SENSOR) > 6)
    {
      inertial_measurement_unit.update();
      servo_ultra_pid();
    }
    stop_motors();

    // do backward pid to becomes straight

    steering_servo.write(STEERING_CENTER_POSITION );
    delay(100);
    drive_backward(35);
    while ( get_instant_distance(LEFT_BACK_SENSOR) > 6 )
    {
      inertial_measurement_unit.update();
      backward_orientation_control();
      servo_ultra_pid();
    }
  }
}

void PARKING_CCW() {
  steering_servo.write(STEERING_CENTER_POSITION);
  drive_forward(25);

  // walk slowly  until finding the parking lot
  while (get_instant_distance(RIGHT_SIDE_SENSOR) > 20)
  {
    inertial_measurement_unit.update();
    forward_orientation_control();
    servo_ultra_pid();
  }
  stop_motors();

  // enter to the parking lot
  steering_servo.write(STEERING_CENTER_POSITION + 40);
  delay(100);
  drive_forward(35);
  while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle + 30)
  {
    inertial_measurement_unit.update();
    servo_ultra_pid();
  }
  stop_motors();
  steering_servo.write(STEERING_CENTER_POSITION - 20);
  delay(100);
  while ( inertial_measurement_unit.getAngleZ() < imu_reference_angle )
  {
    inertial_measurement_unit.update();
    servo_ultra_pid();
  }

  // repeat until the right sensor reads small distance which means that the robot is completly inside the parking lot

  while (get_instant_distance(RIGHT_SIDE_SENSOR) > 3.5)
  {

    // do a right turn to become closer to the wall

    steering_servo.write(STEERING_CENTER_POSITION + 25);
    delay(100);
    drive_forward(35);
    while ( get_instant_distance(FRONT_SENSOR) > 6)
    {
      inertial_measurement_unit.update();
      servo_ultra_pid();
    }
    stop_motors();

    // do backward pid to becomes straight

    steering_servo.write(STEERING_CENTER_POSITION );
    delay(100);
    drive_backward(35);
    while ( get_instant_distance(RIGHT_BACK_SENSOR) > 6 )
    {
      inertial_measurement_unit.update();
      backward_orientation_control();
      servo_ultra_pid();
    }
  }
}

// ============================================================================
// SYSTEM INITIALIZATION
// ============================================================================

/**
   Initialize all hardware components and sensors
*/
void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize I2C communication
  Wire.begin();

  // Initialize IMU
  byte imu_status = inertial_measurement_unit.begin();
  Serial.print(F("MPU6050 Status: "));
  Serial.println(imu_status);

  while (imu_status != 0) {
    // Wait for successful IMU initialization
  }

  Serial.println(F("Calibrating IMU offsets - keep robot stationary"));
  delay(1000);

  inertial_measurement_unit.calcOffsets();
  Serial.println("IMU calibration complete!\n");

  // Initialize motor control pins
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);

  // Initialize servo motors
  steering_servo.attach(11);
  right_gripper_servo.attach(8);
  left_gripper_servo.attach(5);

  // Set initial servo positions
  left_gripper_servo.write(130);
  right_gripper_servo.write(115);
  steering_servo.write(STEERING_CENTER_POSITION);

  // Set initial IMU reference
  inertial_measurement_unit.update();
  imu_reference_angle = inertial_measurement_unit.getAngleZ();

  Serial.println("System initialization complete - Beginning navigation");
}

// ============================================================================
// MAIN NAVIGATION LOOP
// ============================================================================

/**
   Main navigation control loop
   Implements wall following, obstacle avoidance, and autonomous turning
*/
void loop() {
  // Start the round and determine the driving direction
  if (get_instant_distance(RIGHT_SIDE_SENSOR) < get_instant_distance(LEFT_SIDE_SENSOR))
  {
    Serial.println("CCW");
    left_turn_completed = true;
    startup_ccw();
  }
  else
  {
    Serial.println("CW");
    right_turn_completed = true ;
    startup_cw();
  }


  for (int sec_num = 0; sec_num < 10; sec_num++) // pass all sections except the starting section and the ending section
  {
    if (sec_num < 4) // if it is the first lap, take color data from camera and store them in the array
    {
      READ_PILLAR_COLOR();
    }
    // pass the two pillars in the section depending on their colors if there is one pillar, it will be duplicated
    if (colors[current_pillar] == 'R') pass_red_pillar();
    else if (colors[current_pillar] == 'G') pass_green_pillar();
    current_pillar = (current_pillar + 1) % 8;

    if (colors[current_pillar] == 'R') pass_red_pillar();
    else if (colors[current_pillar] == 'G') pass_green_pillar();
    current_pillar = (current_pillar + 1) % 8;

    // Turn to the next section
    if (right_turn_completed) execute_right_turn();
    else if (left_turn_completed) execute_left_turn();

  }

  // park the robot

  if (right_turn_completed) PARKING_CW();
  else if (left_turn_completed) PARKING_CCW();

}
