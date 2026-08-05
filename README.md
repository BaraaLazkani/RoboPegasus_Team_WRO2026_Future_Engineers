RoboPegasus — WRO Future Engineers 2026
====

This repository contains the engineering materials of RoboPegasus's
self-driving vehicle for the WRO Future Engineers competition, season 2026.

## Engineer's Documentation on GitHub

### Why this section exists

Real engineering means not only building a solution but communicating it, so
alongside the vehicle design and code, our team must provide documentation
of our engineering progress, the final vehicle design, and the final
vehicle source code
[Rule 7, p.8: "Real engineering is about creating a solution and communicating or sharing the"].
This documentation lives primarily on GitHub, with all information and
documentation for the international competition written in English
[Rule 7, p.8: "Real engineering is about creating a solution and communicating or sharing the"].
The Engineering Journal and this GitHub repository together are meant to
demonstrate our engineering process (not only the final robot), let judges
evaluate our design decisions and systems thinking, and provide enough
detail that another team could reproduce our robot
[Rule appendix-C, p.44: "C.1 Purpose of the Engineering Journal and GitHub Repository The Engineering Journal"].
Documentation is worth 30 of the total competition points
[Rule 10.2.3, p.21: "30 points for the engineering journal documentation"].

### Repository

Our 2026 repository is public at
[github.com/BaraaLazkani/RoboPegasus_Team_WRO2026_Future_Engineers](https://github.com/BaraaLazkani/RoboPegasus_Team_WRO2026_Future_Engineers),
which satisfies the requirement that GitHub repositories be set for public
viewing with visible content
[Rule 7.b4.5, p.9: "GitHub repositories must be set for public viewing and the content must"].
Per the rules, the repository has to stay public from the moment it is
submitted for an international competition through at least 12 months
afterward
[Rule 7.b4.4, p.9: "More commits are allowed. The repository must contain a README.md file with"].

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
be clearly organized, with meaningful GitHub structure
[Rule C.b38, p.48: "GitHub structure and clarity"],
correct file organization
[Rule C.b41, p.48: "File organization"],
and all of the required technical files -- CAD, code, and wiring
information -- present and included
[Rule C.b42, p.48: "CAD, code, wiring and related technical files"].
The repository's code covers all components programmed to participate in
the competition, and may also include the files used by 3D printers and
laser cutting machines to produce the vehicle's elements
[Rule 7.b4, p.9: "Link to a GitHub public repository with the code for all components"].
The team has already produced this design data: 3D-printed part files
(`models/STL Files/`) and laser-cut part files (`models/Cut/`).

### What the documentation must include

- **Design discussion.** A discussion of, and motivation for, the vehicle's
  mobility, power and sense, and obstacle management design
  [Rule 7.b1, p.9: "Discussion, information and motivation for the vehicle's mobility, power and sense, and"].
  This content lives in this repository's dedicated design sections (to be
  drafted separately), not duplicated here.
- **Photos.** Photos of the vehicle from every side, from the top and
  bottom, plus a team photo
  [Rule 7.b2, p.9: "Photos of the vehicle (from every side, from top and bottom), and"].
- **Videos.** A YouTube link for each challenge showing the vehicle driving
  autonomously, with at least 30 seconds of actual driving shown per video
  [Rule 7.b3, p.9: "URL to YouTube (should be either public or accessible by link) showing"].
  *Status: not yet recorded -- links to be added once available. This is a
  known gap, not an oversight; do not treat the absence of a link here as
  the section being complete.*
- **README.** A README.md with a description of the designed solution of
  at least 5000 characters in English, covering what modules the code
  consists of, how they relate to the vehicle's electromechanical
  components, and the process to build/compile/upload the code to the
  vehicle's controllers
  [Rule 7.b4.4, p.9: "More commits are allowed. The repository must contain a README.md file with"].
  README content and structure is itself one of the things judges evaluate
  under the reproducibility criterion
  [Rule C.b40, p.48: "README content and structure"].
  *This 5000-character requirement applies to the complete README, which
  this section alone does not yet satisfy -- it will be met once the
  design, sensor, and software sections are merged in alongside this one.*
- **Code comments.** Code on GitHub (and in the hard copy) must be well
  documented with comments, since judges may not have access to the
  specific development tools a team used
  [Rule 7.b5, p.10: "Code provided on GitHub and Hard Copy must be well documented with"].

### Commit history

The rules require the repository's commit history to contain at least
three commits on a fixed schedule: the first no later than 2 months before
the competition, containing at least 1/5 of the final code
[Rule 7.b4.1, p.9: "the first commit not later than 2 months before the competition –"];
the second no later than 1 month before the competition
[Rule 7.b4.2, p.9: "The second commit not later than 1 month before the competition,"];
and the third no later than 2 weeks before the competition, which is the
commit primarily used for evaluation and scoring
[Rule 7.b4.3, p.9: "The third commit not later than 2 weeks before the competition. Note:"].

The team's approach is to commit continuously as work is finished, rather
than working to a fixed schedule, with contributions from every team
member and as many commits as make sense (distributed roughly evenly
across the team, without forcing an artificial split) -- as long as this
still lands at least one real commit inside each of the three required
windows above. This satisfies the rule that more commits than the minimum
three are allowed
[Rule 7.b4.4, p.9: "More commits are allowed. The repository must contain a README.md file with"],
and supports a meaningful commit history as evaluated under the
reproducibility criterion
[Rule C.b39, p.48: "Commit history (at least three meaningful commits)"]
and its corresponding checklist question
[Rule C.b63, p.51: "Do we have at least three meaningful commits with clear messages?"].

### Reproducibility and GitHub Quality

This is one of five criteria judges use to evaluate our documentation,
scored on the same four-level scale as the others (0/2/4/6 points)
[Rule C.b37, p.48: "Clear decisions made under constraints such as power, weight, processing and time."].
At the top level, judges look for a fully reproducible robot, a clear
GitHub project structure, meaningful commit messages, a documented testing
workflow, and versioning or release notes -- for example: *"Our GitHub
repository contains all code, CAD, STL files and wiring diagrams. The
README explains how to assemble the robot step by step. Each major change
is recorded with a commit message ... Release v1.0 corresponds to the
regional event, and v2.0 to the final international version."*
[Rule C.b91, p.54: "Level 6 example “Our GitHub repository contains all code, CAD, STL files"].
A README of at least 5000 characters with required commits present and
CAD/code/wiring included, such that another team could reproduce the
robot with reasonable effort, scores at the next level down
[Rule C.b92, p.54: "Level 4 example “The repository includes the full code base, 3D models"].
A repository that exists but has poor structure, missing or unclear files,
and limited reproducibility scores lower still
[Rule C.b93, p.54: "Level 2 example “We uploaded our final code to GitHub. The README"],
and a missing, empty, or inaccessible repository scores zero
[Rule C.b94, p.54: "Level 0 example Missing repository, empty repository or repository that cannot be"].

Reproducibility of the robot itself is one of the things evaluators
specifically look for
[Rule C.b43, p.49: "Reproducibility of the robot What evaluators are looking for:"],
alongside professional, usable documentation
[Rule C.b44, p.49: "Professional and usable documentation."]
and evidence that the repository reflects our actual engineering process,
not just a final code dump
[Rule C.b45, p.49: "Evidence that the repository reflects the engineering process, not only a final"].
Self-check questions we should be able to answer "yes" to before
submission: could another team rebuild our robot from our documentation
[Rule C.b61, p.50: "Could another team rebuild our robot from our documentation?"];
does our README explain how the system works and how to build it
[Rule C.b62, p.51: "Does our README explain how the system works and how to build"];
and are CAD, wiring, and code files all inside the repository
[Rule C.b64, p.51: "Are CAD, wiring, and code files all inside the repository? C.6 Glossary"]
-- for which we already have real evidence: the STL and DXF part files
now included in `models/`.

### Hard copy

A hard copy (the Engineering Journal) must also be submitted at the
international final; it exists mainly as a fallback in case the GitHub
repository is inaccessible, and to help judges track teams during the
competition, but GitHub remains the main source for scoring
[Rule 7.b5, p.10: "Code provided on GitHub and Hard Copy must be well documented with"].

*Team decision: the hard copy itself is out of scope for now. The team
plans to write the Engineering Journal PDF only after the GitHub
repository/README is complete, so this section intentionally does not
draft that content yet.*

## Mobility and Mechanical Design

This section covers the discussion and motivation for the vehicle's mobility
design, as part of the design discussion required for the repository's
documentation
[Rule 7.b1, p.9: "Discussion, information and motivation for the vehicle's mobility, power and sense, and"].
It corresponds to the "Mobility and Mechanical Design" criterion judges use
to evaluate our documentation, which specifically looks at our chassis
design choices
[Rule C.b7, p.45: "Chassis design choices"],
our steering and drive mechanism
[Rule C.b8, p.45: "Steering and drive mechanism"],
our torque and speed reasoning
[Rule C.b9, p.45: "Torque and speed reasoning"],
mechanical stability and rigidity
[Rule C.b10, p.46: "Mechanical stability and rigidity"],
and justification of our design choices
[Rule C.b11, p.46: "Justification of design choices What evaluators are looking for:"].

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
look for
[Rule C.b14, p.46: "Use of testing to refine the mechanical design. Criterion 2: Power and"]
-- for example, judges specifically credit documentation showing testing
between alternative configurations with a measured, quantified outcome,
such as *"We tested two gear ratios: 1:30 and 1:50 ... We selected 1:50
because it increased lap consistency from 60 percent to 85 percent over 20
runs"*
[Rule C.b75, p.52: "Level 6 example “We tested two gear ratios: 1:30 and 1:50. At"].
By contrast, a description that only states the mechanism used (for
example, *"Our robot uses a differential drive with two 12 V DC motors and
omni wheels ... shown in Figure 3"*) without a testing/tuning narrative
scores at the next level down
[Rule C.b76, p.52: "Level 4 example “Our robot uses a differential drive with two 12"],
a description with no diagrams or reasoning (*"Our robot has a strong
chassis with four wheels and two motors. It drives well and is stable on
the track"*) scores lower still
[Rule C.b77, p.52: "Level 2 example “Our robot has a strong chassis with four wheels"],
and a photo with no explanation at all scores zero
[Rule C.b78, p.52: "Level 0 example “Here is a picture of our robot.” (No further"].

Judges also specifically look for whether we understood how mechanical
design affects performance
[Rule C.b12, p.46: "Evidence that the team understood how mechanical design affects performance."],
and whether we clearly explained why our particular drive and steering
solution was selected
[Rule C.b13, p.46: "Clear explanation of why a particular drive and steering solution was selected."].
Self-check questions for this section: have we explained why we chose this
chassis and drive system
[Rule C.b49, p.50: "Have we explained why we chose this chassis and drive system?"];
do we include diagrams of the mechanical layout
[Rule C.b50, p.50: "Do we include diagrams of the mechanical layout?"];
and did we describe any tests or changes that improved the design
[Rule C.b51, p.50: "Did we describe any tests or changes that improved the design? Power"].

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

