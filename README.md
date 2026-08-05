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

