#---------------------------------------------------
# $ make compile:	execute 'compile' target
# $ make all:		execute 'all' target
# $ make clean:		execute 'clean' target
#---------------------------------------------------

# path for searching dependencies
VPATH = ../../ ./
# dependencies for execute 'all' target
DEPENDENCIES = main.c mergesort.c common/common.c basic/time/timeutils.c

all: clean compile link

# link object files and create executable
link:	compile
	gcc -o main.out main.o mergesort.o common.o timeutils.o
	
# compile to object files .o
compile:	$(DEPENDENCIES)
	gcc -c main.c mergesort.c ../../common/common.c ../../basic/time/timeutils.c -I../../
	
clean:
	rm -rf *.o main.out