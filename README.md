# monday-robot-arm
Arduino code for my 6dof robot arm, "Monday"

See demo here:
[Demo](https://www.youtube.com/shorts/c_6ih5lV6vI)

File structure:
`Monday_Brain.ino` is the main program
---> `homingFunction.ino` function for returning the arm to its home position
---> `lampFunction.ino` function for controlling the arm to the "lamp" position (as seen in the demo vid ^)
---> `randomFunction.ino` function for controlling the arm to a random position (may be risky due to the possibility of encountering a singularity!)
