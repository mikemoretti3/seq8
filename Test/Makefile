# I would normally use cmake but I just don't feel like going through that rigamarole for this simple thing
# And I've already spent way too much time making this work without dealing with using a simulator to run the unit tests inside my IDE

TOP=..

EXE=.exe

CFLAGS=-g

UNITY_O = unity.o 

APP_O = RotaryEncoder.o

all:: TestRotaryEncoder$(EXE)
	./TestRotaryEncoder$(EXE)

TestRotaryEncoder$(EXE): TestRotaryEncoder.o $(UNITY_O) $(APP_O)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -I. -I$(TOP)/App -o $@ $<

RotaryEncoder.o: $(TOP)/App/Drivers/RotaryEncoder.c
	$(CC) $(CFLAGS) -c -I$(TOP)/App -o $@ $<
