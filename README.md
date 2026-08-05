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

