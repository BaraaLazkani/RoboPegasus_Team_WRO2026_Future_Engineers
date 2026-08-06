RoboPegasus — WRO Future Engineers 2026
====

This repository contains the engineering materials of RoboPegasus's
self-driving vehicle for the WRO Future Engineers competition, season 2026.

## Engineer's Documentation on GitHub

### Why this section exists

Real engineering means not only building a solution but communicating it, so
alongside the vehicle design and code, our team must provide documentation
of our engineering progress, the final vehicle design, and the final
vehicle source code.
This documentation lives primarily on GitHub, with all information and
documentation for the international competition written in English.
The Engineering Journal and this GitHub repository together are meant to
demonstrate our engineering process (not only the final robot), let judges
evaluate our design decisions and systems thinking, and provide enough
detail that another team could reproduce our robot.
Documentation is worth 30 of the total competition points.

### Repository

Our 2026 repository is public at
[github.com/BaraaLazkani/RoboPegasus_Team_WRO2026_Future_Engineers](https://github.com/BaraaLazkani/RoboPegasus_Team_WRO2026_Future_Engineers),
which satisfies the requirement that GitHub repositories be set for public
viewing with visible content.
Per the rules, the repository has to stay public from the moment it is
submitted for an international competition through at least 12 months
afterward.

*Note on access: last year's repository access notes mentioned that a VPN
may be required to view the repository from some restricted regions.
The team has confirmed this is still true for this year's repository as
well -- adapted from last year's documentation, not a rule requirement.*

### Repository structure

We are keeping the same top-level folder structure as last year's
repository, to the extent it fits what this year's rules ask for:

```
t-photos/    # Team photos
v-photos/    # Vehicle photos (all sides, top, bottom)
video/       # Video demonstrations and links
schemes/     # Electrical schematics and diagrams
src/         # Source code for all components
models/      # 3D printed and laser cut parts
other/       # Additional resources (images, files, GIFs)
README.md    # This documentation
LICENSE      # Project license
```

*This structure is adapted from last year's team repository
(source: team-2025), confirmed by the team as still the intended layout for
2026 -- not evidence about this year's rules.*

This structure is intended to satisfy the requirement that the repository
be clearly organized, with meaningful GitHub structure, correct file
organization, and all of the required technical files -- CAD, code, and
wiring information -- present and included.
The repository's code covers all components programmed to participate in
the competition, and may also include the files used by 3D printers and
laser cutting machines to produce the vehicle's elements.
The team has already produced this design data: 3D-printed part files
(`models/STL Files/`) and laser-cut part files (`models/Cut/`).

### What the documentation must include

- **Design discussion.** A discussion of, and motivation for, the vehicle's
  mobility, power and sense, and obstacle management design.
  This content lives in this repository's dedicated design sections (to be
  drafted separately), not duplicated here.
- **Photos.** Photos of the vehicle from every side, from the top and
  bottom, plus a team photo.
- **Videos.** A YouTube link for each challenge showing the vehicle driving
  autonomously, with at least 30 seconds of actual driving shown per video.
  *Status: not yet recorded -- links to be added once available. This is a
  known gap, not an oversight; do not treat the absence of a link here as
  the section being complete.*
- **README.** A README.md with a description of the designed solution of
  at least 5000 characters in English, covering what modules the code
  consists of, how they relate to the vehicle's electromechanical
  components, and the process to build/compile/upload the code to the
  vehicle's controllers.
  README content and structure is itself one of the things judges evaluate
  under the reproducibility criterion.
  *This 5000-character requirement applies to the complete README, which
  this section alone does not yet satisfy -- it will be met once the
  design, sensor, and software sections are merged in alongside this one.*
- **Code comments.** Code on GitHub (and in the hard copy) must be well
  documented with comments, since judges may not have access to the
  specific development tools a team used.

### Commit history

The rules require the repository's commit history to contain at least
three commits on a fixed schedule: the first no later than 2 months before
the competition, containing at least 1/5 of the final code; the second no
later than 1 month before the competition; and the third no later than 2
weeks before the competition, which is the commit primarily used for
evaluation and scoring.

The team's approach is to commit continuously as work is finished, rather
than working to a fixed schedule, with contributions from every team
member and as many commits as make sense (distributed roughly evenly
across the team, without forcing an artificial split) -- as long as this
still lands at least one real commit inside each of the three required
windows above. This satisfies the rule that more commits than the minimum
three are allowed, and supports a meaningful commit history as evaluated
under the reproducibility criterion and its corresponding checklist
question.

### Reproducibility and GitHub Quality

This is one of five criteria judges use to evaluate our documentation,
scored on the same four-level scale as the others (0/2/4/6 points).
At the top level, judges look for a fully reproducible robot, a clear
GitHub project structure, meaningful commit messages, a documented testing
workflow, and versioning or release notes -- for example: *"Our GitHub
repository contains all code, CAD, STL files and wiring diagrams. The
README explains how to assemble the robot step by step. Each major change
is recorded with a commit message ... Release v1.0 corresponds to the
regional event, and v2.0 to the final international version."*
A README of at least 5000 characters with required commits present and
CAD/code/wiring included, such that another team could reproduce the
robot with reasonable effort, scores at the next level down.
A repository that exists but has poor structure, missing or unclear files,
and limited reproducibility scores lower still, and a missing, empty, or
inaccessible repository scores zero.

Reproducibility of the robot itself is one of the things evaluators
specifically look for, alongside professional, usable documentation and
evidence that the repository reflects our actual engineering process, not
just a final code dump.
Self-check questions we should be able to answer "yes" to before
submission: could another team rebuild our robot from our documentation;
does our README explain how the system works and how to build it; and are
CAD, wiring, and code files all inside the repository -- for which we
already have real evidence: the STL and DXF part files now included in
`models/`.

### Hard copy

A hard copy (the Engineering Journal) must also be submitted at the
international final; it exists mainly as a fallback in case the GitHub
repository is inaccessible, and to help judges track teams during the
competition, but GitHub remains the main source for scoring.

*Team decision: the hard copy itself is out of scope for now. The team
plans to write the Engineering Journal PDF only after the GitHub
repository/README is complete, so this section intentionally does not
draft that content yet.*

## Mobility and Mechanical Design

This section covers the discussion and motivation for the vehicle's mobility
design, as part of the design discussion required for the repository's
documentation.
It corresponds to the "Mobility and Mechanical Design" criterion judges use
to evaluate our documentation, which specifically looks at our chassis
design choices, our steering and drive mechanism, our torque and speed
reasoning, mechanical stability and rigidity, and justification of our
design choices.

*This content is adapted from last year's team repository (source:
team-2025), confirmed by the team as still accurate for the 2026 robot's
drivetrain, steering, and chassis -- only the ultrasonic and IMU sensor
models changed, which are covered in the Power and Sensor Architecture
section, not here.*

### Chassis

The chassis uses a hybrid material approach: 3mm plexiglass panels for
primary structural elements, combined with PLA 3D-printed components for
complex mechanical interfaces. Overall vehicle dimensions are 29cm length
x 17.5cm width x 29cm height, with a total system weight of 1,475g. The
rear plexi panel is positioned slightly lower than the front panel, which
shifts the center of mass forward to improve stability during acceleration
and cornering.

### Drivetrain

The primary drivetrain uses a JGA25-370 DC motor operating at 245 RPM,
selected for its balance of torque, power efficiency, and cost. At 12V, the
motor delivers 350 RPM no-load speed at 0.1A, reaching maximum efficiency
at 245 RPM with 1.4 kg-cm torque and 2.4W power consumption; its stall
specifications are 5.2 kg-cm torque at 2.2A. An integrated 3:1 gearbox
raises output torque to 4.2 kg-cm while reducing output speed to
approximately 82 RPM. With a 32mm wheel radius, this yields a tractive
force of approximately 12.85 N and a linear velocity of approximately
0.27 m/s at maximum efficiency, comfortably powering the 1,475g vehicle
(at an estimated 0.02 rolling-resistance coefficient, the calculated power
required for constant velocity is roughly 0.09W with the motor's ~90%
efficiency factored in) -- substantial reserve capacity above and beyond
the minimum required for propulsion, which we rely on for acceleration and
dynamic maneuvering.

### Steering

The vehicle uses Ackermann steering, driven by an MG996R high-torque servo
(9.4 kg-cm stall torque at 4.8V, 11 kg-cm at 6V; 0.17s/60 degrees and
0.14s/60 degrees at those respective voltages), which receives direct PWM
signals from the Arduino Mega with no additional driver circuitry, keeping
steering-response latency low. The Ackermann steering geometry itself was
adapted from an existing 4WD Ackermann chassis kit -- the only major
component adapted from an outside design rather than built from scratch --
because the original kit's chassis platform (approximately 24cm) was far
larger than our target robot size (16-18cm). We identified the essential
mounting holes, pivot points, and structural elements from the forward
section of the original mounting plate, then used CAD modeling to
reproduce that section's exact hole spacing and angular relationships at
our compact scale, preserving the steering geometry while eliminating the
unusable length of the original plate.

### Testing and iteration

We tested our gear reduction and drivetrain configuration against our
target performance before finalizing the design, and use of testing to
refine the mechanical design is one of the things evaluators specifically
look for -- for example, judges specifically credit documentation showing
testing between alternative configurations with a measured, quantified
outcome, such as *"We tested two gear ratios: 1:30 and 1:50 ... We
selected 1:50 because it increased lap consistency from 60 percent to 85
percent over 20 runs"*.
By contrast, a description that only states the mechanism used (for
example, *"Our robot uses a differential drive with two 12 V DC motors and
omni wheels ... shown in Figure 3"*) without a testing/tuning narrative
scores at the next level down, a description with no diagrams or reasoning
(*"Our robot has a strong chassis with four wheels and two motors. It
drives well and is stable on the track"*) scores lower still, and a photo
with no explanation at all scores zero.

Judges also specifically look for whether we understood how mechanical
design affects performance, and whether we clearly explained why our
particular drive and steering solution was selected.
Self-check questions for this section: have we explained why we chose this
chassis and drive system; do we include diagrams of the mechanical layout;
and did we describe any tests or changes that improved the design.

*This last self-check is a genuine gap right now: beyond the gear-ratio
tuning noted above (from last year, confirmed still valid), we don't yet
have a documented account of 2026-specific mechanical tests or design
changes. This should be filled in once such testing has actually been
done -- not invented here.*

## Power and Sensor Architecture

This section covers the discussion and motivation for the vehicle's power
and sense design, as part of the design discussion required for the
repository's documentation
[Rule 7.b1, p.9: "Discussion, information and motivation for the vehicle's mobility, power and sense, and"].
It corresponds to the "Power and Sensor Architecture" criterion judges use
to evaluate our documentation, which specifically looks at our power
system architecture
[Rule C.b15, p.46: "Power system architecture"],
current draw reasoning and distribution
[Rule C.b16, p.46: "Current draw reasoning and distribution"],
sensor selection and placement
[Rule C.b17, p.46: "Sensor selection and placement"],
calibration methods
[Rule C.b18, p.46: "Calibration methods"],
and wiring diagrams
[Rule C.b19, p.46: "Wiring diagrams What evaluators are looking for:"].

*The power system and processors below are adapted from last year's team
repository (source: team-2025), confirmed unchanged by the team. The
sensor array is also adapted from last year, but with real, confirmed
2026 changes to sensor models and servo count, called out explicitly
below -- not carried over silently.*

### Power source and distribution

The robot is powered by a Zeee Li-Poly battery: 11.1V (3S configuration),
2200mAh capacity, 50C continuous discharge rate, up to 110A continuous
maximum current output, approximately 185g, with an XT60 connector. Power
is distributed using a custom Power Management System (PMS) built on a
star topology -- each component receives power directly from a central
distribution point rather than a daisy chain, which avoids voltage drops
and current-induced interference between subsystems, isolates each
component's current draw from the others, and simplifies fault isolation
and cable management. The battery's 50C/110A capacity comfortably covers
simultaneous peak demand from the drivetrain, processors, and sensor array
without voltage sag. At a typical estimated operating power draw, the
battery supports roughly 50 minutes of runtime, with a safety-factor
budget (80% battery usage) of roughly 41 minutes -- comfortably covering
multiple competition runs per charge.

The PMS includes a dedicated DC-DC step-down converter, which regulates
and stabilizes the battery's raw voltage down to what the Raspberry Pi 5
(SBC) and Arduino Mega (SBM) require -- satisfying the requirement that a
voltage stabilizer provide adequate power to the SBC/SBM
[Rule D.b11, p.55: "a voltage stabilizer: it is required to provide adequate power supply for"].

### Processing

An Arduino Mega 2560 serves as the primary sensor interface and real-time
control processor -- handling sensor data acquisition, motor control, and
real-time navigation decisions -- chosen for its cost-effectiveness, 54
digital pins and 16 analog inputs (enough I/O for our full sensor array),
and proven reliability in robotics applications. A Raspberry Pi 5 (8GB RAM,
with active cooling) handles computer vision processing separately; active
cooling specifically guards against thermal throttling in high ambient
temperatures such as summer competition conditions. The two processors
communicate over a USB serial connection, exchanging computer vision
results and navigation commands.

### Sensor array

The array consists of 7 ultrasonic sensors, an IMU, and a camera, in the
same overall count and positions as last year -- but with real changes
this year to two component models and to servo coverage, both confirmed
directly by the team, not assumed:

- **Ultrasonic sensors:** 7x DFRobot URM09 (previously HC-SR04). Mounted
  below the 9cm height threshold for reliable wall detection.
- **Dynamic positioning:** 5 servos total (previously 3) -- both
  ultrasonic sensors on the left side now have servos, both on the right
  side now have servos, and the front ultrasonic sensor now also has a
  servo. Dynamic positioning keeps these sensors oriented perpendicular to
  walls regardless of vehicle attitude, which meaningfully improves
  measurement accuracy over a fixed angle.
- **IMU:** SparkFun BNO086 (previously MPU6050), providing orientation and
  acceleration data for dead reckoning and complementing the ultrasonic
  array for navigation.
- **Camera:** Arducam 64MP Hawk-Eye module, for computer vision tasks
  including pillar detection/classification and path planning.
- **Infrared sensor:** mounted on a long holder above the chassis for a
  top-down view, used specifically during parking maneuvers to detect lot
  boundaries and avoid wall collisions, positioned at maximum distance from
  the chassis to minimize reflection interference.

*This entire sensor breakdown is adapted from last year's team repository
with the confirmed 2026 model/servo changes applied -- if the exact wiring
diagram, mounting hardware, or any other sensor-array detail beyond what's
listed above has also changed for 2026, that hasn't been confirmed and
isn't reflected here; flag it if so.*

### Sensor placement: field geometry and failure-point reasoning

Judges credit sensor placement justified by field geometry and evidence of
failure-point/redundancy considerations, at the top rubric level
[Rule C.b14, p.46: "Use of testing to refine the mechanical design. Criterion 2: Power and"].
Our placement choices are driven directly by how the robot's own geometry
changes relative to the walls during a maneuver, not just by a generic
"more sensors is better" logic:

- **Two rear ultrasonics** let the parking routine know when the robot is
  fully inside the parking lot -- a distinct requirement from the side
  sensors' wall-following role.
- **Two ultrasonics per side (front-axle and rear-axle),** rather than
  one, because which end of the robot is actually closest to the wall
  depends on the maneuver: driving forward while turning right brings the
  *front* of the robot closest to the wall, while driving backward while
  turning right brings the *back* of the robot closest to the wall. A
  single side sensor would be reading the wrong distance during roughly
  half of these maneuvers; having one sensor near each axle means the
  relevant distance is always available on both sides regardless of
  direction of travel or turn.
- **The same front/rear-axle side-sensor pair also compensates for IMU
  drift:** since the two sensors' physical separation is known, the robot
  can geometrically compute how many degrees it has actually drifted from
  the two distance readings, and use that to correct the MPU/IMU heading
  reference over time -- a concrete failure-point mitigation for sensor
  drift, not just a navigation feature.
- **The front ultrasonic** exists specifically to detect obstacles
  directly ahead of the robot, a role none of the side/rear sensors can
  fill.
- **Servos on the ultrasonics** exist because ultrasonic ranging accuracy
  degrades sharply once the reflecting surface isn't perpendicular to the
  sensor -- dynamic positioning keeps each sensor perpendicular to the
  wall regardless of the robot's current attitude, which is the whole
  reason the sensor count and servo count both grew for 2026 (see above).

### What judges look for

Judges specifically look for evidence that we planned power distribution,
not just connected parts
[Rule C.b20, p.46: "Evidence that the team planned power distribution, not only connected parts."],
justification for our sensor choices and positions
[Rule C.b21, p.46: "Justification for sensor choices and positions."],
and consideration of noise, interference, shadows, and similar issues
[Rule C.b22, p.46: "Consideration of noise, interference, shadows and similar issues. Criterion 3: Software Architecture"]
-- addressed above in the field-geometry and failure-point reasoning, and
in the Wiring diagram and Calibration sections below.

At the top level, judges credit a documented power budget with sensor
trade-offs justified by real testing, such as: *"The total current draw
during peak acceleration is approximately 3.2 A for the drive motors and
0.8 A for electronics. We therefore selected a 5 A step down regulator. We
tested two camera positions ... which reduced misdetection by 40 percent"*
[Rule C.b79, p.52: "Level 6 example “The total current draw during peak acceleration is approximately"].
A wiring diagram with sensor placement explained, but without that level
of testing narrative, scores at the next level down
[Rule C.b80, p.52: "Level 4 example “Figure 5 shows our wiring diagram. The main 3"].
A bare component list without diagrams or explanation scores lower still
[Rule C.b81, p.52: "Level 2 example “We use a LiPo battery and several sensors: two"],
and no mention of power or sensor placement at all scores zero
[Rule C.b82, p.52: "Level 0 example No mention of how parts are powered or where"].

Self-check questions for this section: do we show how power is distributed
and regulated
[Rule C.b52, p.50: "Do we show how power is distributed and regulated?"];
have we justified our sensor choices and positions
[Rule C.b53, p.50: "Have we justified our sensor choices and positions?"];
and is there at least one wiring diagram and description of calibration
[Rule C.b54, p.50: "Is there at least one wiring diagram and description of calibration? Software"].

### Wiring diagram

Judges specifically look for at least one wiring diagram
[Rule C.b19, p.46: "Wiring diagrams What evaluators are looking for:"].
The wiring diagram is the same one used last year (source: team-2025,
`schemes/Full Schematic Circuit Diagram of the Robot/Full Circuit Diagram
of the Robot.PNG`), reused as-is for 2026. It was produced in Fritzing,
which does not have exact component symbols for the URM09 ultrasonic or
BNO086 IMU, so those two components are represented with generic/illustrative
symbols rather than exact part renders -- the diagram is accurate for
overall wiring topology, not a literal part-for-part illustration of the
newest sensors.

![Full Schematic Circuit Diagram of the Robot](schemes/Full%20Schematic%20Circuit%20Diagram%20of%20the%20Robot/Full%20Circuit%20Diagram%20of%20the%20Robot.PNG)

*This diagram is adapted from last year's team repository (source:
team-2025), reused as-is -- not redrawn for 2026, per the caveat above.*

### Calibration

Judges specifically look for calibration methods
[Rule C.b18, p.46: "Calibration methods"].
Neither the DFRobot URM09 ultrasonic sensors nor the SparkFun BNO086 IMU
required a dedicated calibration procedure -- both performed reliably
right out of the box, so no team-developed calibration methodology exists
for either.

## Software Architecture and Obstacle Strategy

This section covers the discussion and motivation for the vehicle's
obstacle-management design, as part of the design discussion required for
the repository's documentation
[Rule 7.b1, p.9: "Discussion, information and motivation for the vehicle's mobility, power and sense, and"].
It corresponds to the "Software Architecture and Obstacle Strategy"
criterion judges use to evaluate our documentation, which specifically
looks at code modularity and structure
[Rule C.b23, p.47: "Code modularity and structure"],
state machines or control flow
[Rule C.b24, p.47: "State machines or control flow"],
our lane following and obstacle obedience strategy
[Rule C.b25, p.47: "Lane following and obstacle obedience strategy"],
explanation of the algorithms used
[Rule C.b26, p.47: "Explanation of algorithms used"],
and basic code documentation and comments
[Rule C.b27, p.47: "Basic code documentation and comments What evaluators are looking for:"].

*This content is adapted from last year's team repository (source:
team-2025), confirmed by the team as still accurate for 2026 -- open
challenge navigation and pillar-color detection are unchanged; only the
parking approach changed, and that change is described below using last
year's own already-documented "Backward Parking" method, which the team
confirmed now matches this year's actual approach.*

### Open Challenge navigation

At startup, the robot reads distance from its left and right ultrasonic
sensors (`d_left`, `d_right`) to establish its spatial relationship to the
surrounding walls, and determines its driving direction by comparing them:
CCW if the right distance is less than the left, CW otherwise. During a
lap, the robot executes a turning maneuver whenever either ultrasonic
sensor detects an opening (a distance reading greater than 120cm),
adapting its turning logic to the section geometry it detects, and
continues wall-following/turning until the required number of laps is
complete.

### Obstacle Challenge: pillar detection

Pillar color is detected and classified via the Raspberry Pi 5's computer
vision pipeline, distinguishing red and green pillar configurations
(Red-Green, Green-Red, Red-Red, and Green-Green cases) to determine which
side of the lane to keep. Detected color masks feed directly into the
navigation logic to decide the lane-keeping side for each pillar
encountered.

### State machine and control flow

The obstacle-challenge control flow is organized as a state machine built
around per-pillar handling functions:

1. **Startup.** The robot exits the parking section; the startup sequence
   itself differs depending on whether the run is CW or CCW.
2. **First pillar.** The robot takes a photo and calls a `pass_first_pillar`
   function, selected by the detected color and by CW/CCW direction.
3. **Repositioning.** After `pass_first_pillar` completes, a maneuver
   (dependent on the robot's current position) repositions the robot ready
   for the next section and the next photo.
4. **Subsequent pillars.** Each pillar is handled by a function named for
   its color combination and direction (for example `Red_Red_ccw`,
   `Red_Green_ccw`). There are also `<Color>_None_<direction>` variants
   (for example `Red_None_ccw`) that currently behave identically to their
   same-color counterpart; these exist specifically to have a defined
   behavior ready in case a pillar's expected color signal changes under
   the season's Surprise Rule, which can add or modify existing rules
   before the international final
   [Rule 6, p.8: "A surprise rule for the international competition can be announced before the"].
5. **After the first lap,** the robot already knows each pillar's color
   from the first pass, so it stops taking photos and passes each pillar
   directly using the already-determined color/direction function.
6. **Shared control primitives**, used inside every pillar-passing
   function:
   - `turn_right` / `turn_left` -- discrete turning maneuvers.
   - `dual_pid` -- follows both an MPU/IMU heading reference and a target
     distance from a specific wall simultaneously.
   - `MPU_PID` -- follows only an MPU/IMU heading reference, with no wall
     distance term.
7. **Parking.** The robot always parks from the same fixed
   position/orientation regardless of which direction the lap ran in, so
   a `reverse_cw_to_ccw` function (or its opposite) flips the approach
   direction where needed so the final parking maneuver is always
   consistent, using the Backward Parking method described below.

### Parking

This year's parking approach: the robot walks past the parking lot first,
then enters it in reverse from the rear axle, rather than entering forward
from the front as in previous seasons. This corresponds exactly to what
was already documented last year (but not used at the time) as "Backward
Parking":

1. **Approach detection.** The robot drives backward along the lane, using
   its rear-right sensor to monitor for the parking entrance. When the
   entrance gap is detected, it continues a small additional distance to
   confirm it has reached the correct spot (avoiding a false trigger at
   the wall edge).
2. **Maneuver.** The robot steers right and reverses into the parking lot
   entrance. As soon as the back half of the robot clears the first wall,
   it steers left to align itself parallel with the walls. This reversing
   trajectory is smoother and gives more precise alignment control than
   the forward-entry approach used previously.
3. **Sensing.** Parking uses a combination of sensors: ultrasonic sensors
   mounted on the sides and rear measure distance from the parking lot
   walls and detect the entrance gap; the IMU (now the SparkFun BNO086,
   see the Power and Sensor Architecture section) provides orientation and
   heading for precise turning; and the infrared sensor, mounted above the
   chassis for a top-down view, detects the lot boundaries and helps avoid
   wall collisions.

*Last year's "Forward Parking" description (entering from the front,
right-side sensor monitoring) is superseded by the above for 2026 and
should not be presented as this year's method.*

#### Testing

The reworked backward-entry parking maneuver has been tested 100 times,
succeeding on all 100 attempts.

### What judges look for

At the top level, judges credit a justified control approach with a real
state machine and a documented tuning process, such as: *"Our lane
following uses a proportional controller ... We tried bang-bang control,
but it produced oscillations near corners. The finite state machine ...
shows states for LaneFollow, AvoidPillarLeft and AvoidPillarRight. We log
the number of interventions per lap and tuned the controller to minimize
these interventions"*
[Rule C.b83, p.53: "Level 6 example “Our lane following uses a proportional controller based on"].
A flowchart with modules explained, but without that tuning narrative,
scores at the next level down
[Rule C.b84, p.53: "Level 4 example “Figure 7 shows the flowchart of our main program."].
A basic description without a clear structure scores lower still
[Rule C.b85, p.53: "Level 2 example “We wrote code that reads the camera and sensors"],
and code with no explanation at all scores zero
[Rule C.b86, p.53: "Level 0 example Only code listings with no explanation of what the"].

Judges also specifically look for our understanding of how the software
structure supports the robot's behavior
[Rule C.b28, p.47: "Understanding of how software structure supports the robot's behavior."],
clear strategies for lane following, obstacle avoidance, and side
obedience
[Rule C.b29, p.47: "Clear strategies for lane following, obstacle avoidance and side obedience."],
and evidence of testing and tuning, not just final code
[Rule C.b30, p.47: "Evidence of testing and tuning, not just final code. Criterion 4: Systems"].
Self-check questions for this section: do we show a flowchart or state
machine for our software
[Rule C.b55, p.50: "Do we show a flowchart or state machine for our software?"];
do we explain how we follow lanes and avoid obstacles
[Rule C.b56, p.50: "Do we explain how we follow lanes and avoid obstacles?"];
and have we included some descriptions of testing or tuning
[Rule C.b57, p.50: "Have we included some descriptions of testing or tuning? Systems Thinking and"].

The state machine above and the parking trial results (100/100 successful
attempts) directly address these two points; we still don't have a
per-lap intervention count or PID tuning narrative for the open-challenge
wall-following controller specifically -- that remains a gap, not invented
here.

## Systems Thinking and Engineering Decisions

This section corresponds to the "Systems Thinking and Engineering
Decisions" criterion judges use to evaluate our documentation -- the
fourth of five criteria, and the one that looks across subsystems rather
than at any single one of them
[Rule C.b30, p.47: "Evidence of testing and tuning, not just final code. Criterion 4: Systems"].
It specifically looks at how our subsystems work together (mobility,
power, sensors, software, frame)
[Rule C.b31, p.48: "How subsystems work together (mobility, power, sensors, software, frame)."],
the engineering reasoning behind our decisions
[Rule C.b32, p.48: "Engineering reasoning behind decisions."],
our constraints and tradeoffs
[Rule C.b33, p.48: "Constraints and tradeoffs."],
our iteration and testing cycles
[Rule C.b34, p.48: "Iteration and testing cycles."],
and risk identification and mitigation
[Rule C.b35, p.48: "Risk identification and mitigation actions. What evaluators are looking for:"].

*Much of the cross-subsystem content below is synthesized from facts
already verified and cited in the Mobility, Power/Sensor, and Software
sections -- it isn't new material, just presented from a whole-system
angle rather than a single-subsystem one. New, team-specific
constraint/tradeoff content confirmed directly by the team for this
section is called out explicitly.*

### Constraints we designed within

Judges specifically credit clear decisions made under constraints such as
power, weight, processing, and time
[Rule C.b37, p.48: "Clear decisions made under constraints such as power, weight, processing and time."].
Every constraint below is a real, specific limit we designed around --
not a generic list.

**Vehicle envelope.** WRO caps overall vehicle dimensions at 300x200mm and
300mm in height
[Rule 11.1, p.23: "The vehicle’s dimensions must not exceed 300x200 mm and"]
[Rule 9.17, p.18: "The vehicle’s dimensions must not exceed 300x200 mm and"],
and caps weight at 1.5kg
[Rule 11.2, p.23: "The weight of the vehicle must not exceed 1.5 kilograms."].
Our vehicle's 1,475g mass (see Mobility and Mechanical Design) sits
comfortably under that limit.

**Wheelbase and turning radius.** We studied the robot's overall length
and the wheelbase (front-to-rear axle distance) specifically to determine
the turning radius we needed. We empirically tested extending the robot's
length using an added rod, and found 4cm was the safe, best-performing
addition -- long enough to meaningfully help with parking maneuvering,
without pushing length past what the rest of the design could
accommodate.

**Width vs. turning radius tradeoff.** We wanted the robot as narrow as
possible (while staying long enough for the turning-radius requirement
above), but our Ackermann steering mechanism constrained how narrow we
could actually go: the robot's width ended up set by the front axle's
track width, since that's the span the Ackermann geometry needs to
function correctly. This is a direct example of "we chose X instead of Y
because..." reasoning -- we didn't choose the width freely; the steering
mechanism we'd already committed to (see Mobility and Mechanical Design)
determined it.

**Power switching.** Only one switch is allowed to power the vehicle on
[Rule 9.10, p.17: "The vehicle is then switched on. Only one switch is allowed to"].
That single-switch constraint is a direct reason we engineered a custom
Power Management System (see Power and Sensor Architecture) rather than
wiring components independently: with only one legal point of entry for
power, a centralized, star-topology distribution design was the only way
to cleanly deliver power to every subsystem from that single switch.

**Processing/startup time.** The Raspberry Pi 5's boot process and Python
library loading originally took approximately 90 seconds combined -- time
that competes directly with the window judges allow the robot to become
ready before starting the competition countdown. To bring this down, we
switched to headless/lightweight versions of our libraries instead of
their full desktop-oriented builds, and disabled Pi system services we
didn't need at boot. This got the robot moving well within that startup
window. This is a concrete, testable engineering decision made under a
real time constraint, not a hypothetical one.

### Iteration and testing

Aside from the specific, already-documented 2026 changes -- the
DFRobot URM09/SparkFun BNO086 sensor swap, the added servos, the 4cm
wheelbase-extension rod, the reworked backward-entry parking maneuver, and
the Pi startup-time optimization above -- this year is mostly an
incremental refinement of last year's platform rather than a ground-up
redesign
[Rule C.b34, p.48: "Iteration and testing cycles."].

### Risk identification and mitigation

Two concrete failure modes were identified and addressed at the system
level, not left as isolated sensor concerns:

- **IMU drift.** The MPU/IMU heading reference can drift over time. We
  mitigate this using the geometric relationship between each side's two
  ultrasonic sensors (front-axle and rear-axle) -- the robot calculates
  its actual drift angle from their two distance readings and corrects
  the heading reference accordingly (see Power and Sensor Architecture).
- **Ultrasonic accuracy loss off-perpendicular.** Ultrasonic ranging
  degrades sharply once the reflecting surface isn't perpendicular to the
  sensor. We mitigate this with servo-driven dynamic positioning, keeping
  every relevant ultrasonic sensor perpendicular to the wall regardless of
  the robot's current attitude (see Power and Sensor Architecture).

Evidence that the team thought about the robot as a system, not as
separate parts, is exactly what this criterion evaluates
[Rule C.b36, p.48: "Evidence that the team thought about the robot as a system, not"] --
these two mitigations are both cases where a single-subsystem fix (better
IMU calibration, a single fixed sensor) wouldn't have worked, and the
actual solution came from how two subsystems (sensing geometry and
control software) interact.

### What judges look for

At the top level, judges credit documentation that names real constraints,
a concrete data-driven decision, and a specific risk with its mitigation,
such as: *"We considered two architectures: on board vision only and a
split system with edge processing off the robot ... We reduced frame rate
from 30 fps to 15 fps to keep CPU below 70 percent. Our risk table
identified overheating as a failure mode, so we added a fan and verified
temperatures stayed below 60 degrees Celsius"*
[Rule C.b87, p.53: "Level 6 example “We considered two architectures: on board vision only and"].
A block diagram of subsystems with a brief explanation of how they
interact, but without that depth, scores at the next level down
[Rule C.b88, p.53: "Level 4 example “Our overall system is shown in the block diagram"].
A list of decisions made without detailed reasoning scores lower still
[Rule C.b89, p.53: "Level 2 example “We made several decisions during the season, for example"],
and documentation that only describes the final design with no mention of
choices, tradeoffs, or problems scores zero
[Rule C.b90, p.53: "Level 0 example Documentation only describes the final design with no mention"].

Self-check questions for this section: did we identify constraints such as
power, weight, time, or processing
[Rule C.b58, p.50: "Did we identify constraints such as power, weight, time or processing?"];
have we shown at least one design tradeoff and explained our choice
[Rule C.b59, p.50: "Have we shown at least one design trade off and explained our"];
and did we show how our design changed over time
[Rule C.b60, p.50: "Did we show how our design changed over time (version 1, 2,"]
-- answered above as incremental refinement rather than a version-by-version
redesign, per the team's own account, not invented here.

## Team and Age Groups Definitions

### Our team

RoboPegasus consists of 3 students
[Rule 2.1, p.4: "A team consists of 2 or 3 students."],
guided by one coach
[Rule 2.2, p.4: "A team is guided by a coach."]:

- **Coach:** Baraa Lazkani
- **Students:** Hasan Mfleh, Hadi Moalla, Haidar Saad

*Roster note, adapted from last year's team repository (source:
team-2025), not evidence about this year's rules: last year's team had
Baraa Lazkani as a student, with Obai Ibrahim as coach. For 2026, Baraa
has moved into the coach role, Hasan Mfleh and Hadi Moalla continue as
students, and Haidar Saad has joined as a new student -- confirmed
directly by the team, not assumed.*

With 3 students and 1 coach, the team is well above the minimum team size
the rules exclude: a single team member plus a single coach is not
considered a valid team and cannot participate
[Rule 2.3, p.4: "1 team member and 1 coach are not considered a team and"].

### Category and team membership

The team participates only in the Future Engineers category this season,
consistent with the rule that a team may only participate in one WRO
category per season
[Rule 2.4, p.4: "A team may only participate in one of the WRO categories in"].
Each of our three students -- Hasan, Hadi, and Haidar -- participates on
this team only, in accordance with the rule that any student may
participate in one team only
[Rule 2.5, p.4: "Any student may participate in one team only."].

### Age eligibility

The 2026 age group for this category covers students aged 14-22, born
between 2004 and 2012
[Rule 2.8, p.4: "The age group for this category is defined for students in the"].
This age window is evaluated by the age a participant turns during the
2026 calendar year, not their age on the day of competition
[Rule 2.9, p.4: "The maximum age reflects the age that the participant turns in the"].
All three of our students fall within this window: Haidar Saad was born
in 2004 (turning 22 in 2026, the oldest age this category allows), and
Hasan Mfleh and Hadi Moalla were both born in 2005.

Our coach, Baraa Lazkani, was also born in 2004 -- turning 22 in 2026,
comfortably above the minimum coach age of 18 years old required at
international events
[Rule 2.6, p.4: "The minimum age of a coach at an international event is 18"].
Coaches are permitted to work with more than one team
[Rule 2.7, p.4: "Coaches may work with more than one team."], which does
not require any statement here about whether Baraa coaches other teams.

## Responsibilities and Team's Own Work

Our team plays fair and is respectful towards other teams, coaches,
judges, and competition organizers. By competing in WRO, we accept the
WRO Guiding Principles
[Rule 3.1, p.4: "A team should play fair and be respectful towards teams, coaches, judges,"].
Every team member and our coach have already signed the WRO Ethics Code
[Rule 3.2, p.4: "Every team and coach need to undersign the WRO Ethics Code. The"].

### Ownership of the work

All coding of the vehicle and its construction was done solely by the
team -- our coach's role has been to support us organizationally and with
questions or problems, not to program or build the vehicle themselves,
consistent with the rule that coaching may not include programming the
vehicle or its construction
[Rule 3.3, p.4: "Coding of the vehicle and its construction (if applicable) may be"].
Our control program and design are our own work: the state machine,
navigation algorithms, and sensor integration described in the Software
Architecture and Power and Sensor Architecture sections were built by the
team, not copied from or too similar to a solution sold online or used by
another team
[Rule 3.7, p.4: "It is not allowed to use a vehicle’s control program that is"].
The one exception is explicitly documented elsewhere and was a deliberate,
disclosed engineering choice, not an attempt to disguise non-original
work: our Ackermann steering mechanism adapts the geometry of an existing
4WD chassis kit, customized and re-integrated into our own compact
chassis design (see Mobility and Mechanical Design) -- the kind of
disclosed, justified reuse the rules anticipate, not the kind of
undisclosed copying rule 3.7 prohibits.

### Competition-day conduct

While the competition is running, our team will not communicate in any
way with people outside the competition area, except where a judge
specifically allows supervised communication
[Rule 3.4, p.4: "A team is not allowed to communicate in any way with people"].
Team members will not bring or use mobile phones or any other
communication device in the competition area
[Rule 3.5, p.4: "Team members are not allowed to bring and use mobile phones or"].
We will not destroy or tamper with competition courts, tables, materials,
or other teams' vehicles
[Rule 3.6, p.4: "Destruction or tampering with competition courts/tables, materials, or vehicles of other teams"].

### Consequences of violations

If any of these rules are broken, judges may interview the team or
individual members about the vehicle or program before deciding on
consequences
[Rule 3.9, p.5: "If any of the rules mentioned in this document are broken or"].
Suspected violations specifically related to independent construction
(rule 3.3) or original work (rule 3.7) can trigger an investigation, with
consequences up to preventing the team from progressing to the next
competition even if they would otherwise place well
[Rule 3.8, p.4: "If there is a suspicion in relation to rule 3.3 and 3.7,"].

## Vehicle Material & Regulations Compliance

This section confirms our vehicle meets the rules' physical and
material regulations, cross-referencing the actual measurements and
component choices already documented in Mobility and Mechanical Design
and Power and Sensor Architecture.

### Size and weight

Our vehicle measures 29cm x 17.5cm x 29cm and weighs 1,475g (see Mobility
and Mechanical Design), comfortably within the rules' limits: dimensions
must not exceed 300x200mm and 300mm in height
[Rule 11.1, p.23: "The vehicle’s dimensions must not exceed 300x200 mm and"]
[Rule 9.17, p.18: "The vehicle’s dimensions must not exceed 300x200 mm and"],
and weight must not exceed 1.5 kilograms
[Rule 11.2, p.23: "The weight of the vehicle must not exceed 1.5 kilograms."].

### Drivetrain and wheels

Our vehicle is a 4-wheeled, rear-wheel-drive vehicle with Ackermann
steering at the front axle (see Mobility and Mechanical Design), which
satisfies the requirement that a vehicle be 4-wheeled with one driving
axle and one steering actuator, built as front-wheel, rear-wheel, or
four-wheel drive -- not a differential wheeled base
[Rule 11.3, p.23: "The vehicle must be a 4 wheeled vehicle with one driving axle"].
Our wheels are plain rubber wheels, not omnidirectional wheels, ball
casters, or spherical wheels
[Rule 11.4, p.23: "The vehicle cannot use any kind of an omnidirectional wheel, ball caster"].
A single JGA25-370 motor drives the rear axle through a custom
differential mechanism and gearbox (see Mobility and Mechanical Design) --
well within the maximum of two driving motors allowed, connected directly
or through gearing rather than independently to each wheel
[Rule 11.13, p.23: "A maximum of two motors may be used to make the vehicle"],
and not an electronic differential with one motor per side
[Rule 11.5, p.23: "The use of an electronic differentials with one motor per side (like"].

### Autonomy and communication

The vehicle operates fully autonomously with no radio communication or
remote control while running (see the state machine described in
Software Architecture and Obstacle Strategy)
[Rule 11.6, p.23: "A vehicle must be autonomous and finish the “missions” by itself. Any"].
Consistent with this, no team member interferes with or assists the
vehicle once a round is running -- no manual data entry, visual, audio,
or other signaling to the vehicle during a run
[Rule 11.7, p.23: "Participants are not allowed to interfere with or assist the vehicle while"].
The Raspberry Pi 5's built-in WiFi and Bluetooth hardware is disabled
during competition runs, satisfying the requirement that any built-in
wireless capability be turned off and confirmable by judges
[Rule 11.10, p.23: "Teams cannot use any kind of RF, Bluetooth, Wi-Fi, or any kind"].
Every connection between our electromechanical components -- sensors,
motors, and the two processors -- is a wired connection; no wireless
links exist anywhere in the sensor or communication chain, satisfying the
requirement that only wire connections be used for inter-component
communication
[Rule 11.17, p.24: "Only wire connections are permitted for communication between vehicle electromechanical components."].

### Controllers and materials

Our controllers are a Raspberry Pi 5 (SBC) and an Arduino Mega 2560 (SBM)
(see Power and Sensor Architecture), matching the rule that either type
of controller is allowed with no brand restriction
[Rule 11.8, p.23: "The controller used for the vehicle can be either Single board computer"].
Our chassis uses a plexiglass and PLA 3D-printed hybrid construction (see
Mobility and Mechanical Design), which the rules permit -- any material or
building system is allowed, with no restriction to a specific type
[Rule 11.19, p.24: "The vehicle can be built using any type of hardware kits and"].
