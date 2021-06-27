# 8-stage Sequencer
This was meant to be the start of work on an 8-stage sequencer Eurorack module using STM32L432KC.  There's a lot more work to be done.  So far, I only wanted to see if I could get some rotary encoder stuff working using a new library I found.  I added some unit testing to test it out but did not finish.
## Directory structure
The top level is the STM32CUBEIDE project, which gets built by the cube ide.
The **Test** directory contains the unit tests using the Unity framework.  It is meant to be built native using make and will not be built as part of the cube project.
