
CC=gcc
CFLAGS = -std=c99 -O2
LDFLAGS= 
LNKLIBS= -lm

MPIRUN =mpirun
NPROCS?=1

EXE=exe
EXESRC=main.c
EXEOBJ=$(patsubst %.c, %.o, $(EXESRC))
CLEAN_FILES+=$(EXE) $(EXEOBJ)

LIB=libfunction.a
LIBSRC=function.c
LIBOBJ=$(patsubst %.c, %.o, $(LIBSRC))
CLEAN_FILES+=$(LIB) $(LIBOBJ)

CLEAN_FILES+= utest utest.o
CLEAN_FILES+= vtest vtest.o

all:	$(EXE) utest vtest

#
# $@ target
# $< first pre-requisite
# $^ all pre-requisites
# Implicit rule for compilation of all objects
%.o:%.c
	$(CC) $(CFLAGS) -c $<

# Rule to build the library
$(LIB): $(LIBOBJ)
	@echo "LIB $@"
	@ar r $@ $^


# Program
$(EXE):	$(EXEOBJ) $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)

run:	$(EXE)
	$(MPIRUN) -n $(NPROCS) ./$< $(X) $(N)

# Unit test
utest:	utest.o $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)
	./$@

# Verification test
vtest:	vtest.o $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)
	./$@

clean:
	rm -f $(CLEAN_FILES)
