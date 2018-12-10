# This Makefile is still simple and the compilations lines are just duplicated.
# This is suboptimal but good enough for this case.
CC=gcc
TARGET=hello
SRC=hello.c main.c

# Notice that the prerequisites can be stored in a variable. 
all:	$(SRC)
	$(CC) -c hello.c
	$(CC) -c main.c
	$(CC) -o $(TARGET) hello.o main.o 

clean:
	rm -f *.o $(TARGET)
