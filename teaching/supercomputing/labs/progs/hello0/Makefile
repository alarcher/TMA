# This is a very basic Makefile.

# First some variables are declared for more flexibility
CC=gcc
TARGET=hello

# Such constructs are called 'rules':
# - the name of the target is followed by a colon and prerequisites,
# - then a list of tab-lead lines are executed when the target is called.
all:  main.c
	$(CC) -o $(TARGET) main.c

# Rules does not need prerequisites, then can just execute a sequence of steps.
# The leading '@' silences the output: executed lines are not printed.
clean:
	@echo "Cleaning the directory"  
	rm -f $(TARGET)
