CC=mpicc
CFLAGS=-std=c99
TARGET=sumpi
NPROCS?=1
NPINTS?=1

all:	$(TARGET)

$(TARGET):
	@$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	@rm -f $(TARGET)

run:	all
	@mpirun -n $(NPROCS) ./$(TARGET) $(NPINTS)
