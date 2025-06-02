# Code for Remapping keyboard keys to key simulations.
This code randomly selects 3 keyboard alphabets, and remaps them, an example would be a,e,t; when key 'a' is pressed 'e' is printed and so forth for 'e' -> 't' & 't' -> 'a'.

# This program is scripted for prank purposes.
Although this is meant to be a prank of some kind it is not permenant, a simple system reboot could fix it all. 

# Compilation
To compile just run compile.sh
```bash
chmod +x compile.sh
compile.sh
```

# Want to make it permenant?
Well one could make the program run at system reboot, meaning everytime system boots up, the program runs. however it might be a little tricky since you cannot directly use cron tab on the compiled program due to the fact the background cron jobs cannot directly interact with X11 graphical session, so we need to set those environment variables first. <br>

**First step** is to run the following in your command line
```bash
echo $DISPLAY
echo $XAUTHORITY
```
And take a note of the output for both commands.<br>

**Second Step** is to create bash script
```bash
#!/bin/bash

export DISPLAY=<output from command 'echo $DISPLAY'>
export XAUTHORITY=<output from command 'echo $AUTHORITY'>

/path/to/compiled/program
```
<br>

**Third step** is to add this bash script to crontab.
```bash
@reboot /bin/bash /path/to/bash/script/created/above
```

