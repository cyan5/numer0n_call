.PHONY: all
all: candidate.o c_func.o
	gcc -Wall -O2 candidate.o c_func.o
candidate.o: candidate.c
	gcc -Wall -O2 -c -o candidate.o candidate.c
c_func.o: c_func.c
	gcc -Wall -O2 -c -o c_func.o c_func.c

.PHONY: clean
clean:
	del /s ./a.out *.o
	@echo clean completed.

# depends header

c_func.o: c_func.h
candidate.o: c_func.h