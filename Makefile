.PHONY: ./a.out
./a.out: main.o cand.o
	gcc -Wall -O2 main.o cand.o
cand.o: main.c
	gcc -Wall -O2 -c -o main.o main.c
cand.o: cand.c
	gcc -Wall -O2 -c -o cand.o cand.c

.PHONY: dev
dev: ./a.out
	./a.out

.PHONY: clean
clean:
	rm -rfv ./a.out main.o cand.o
	@echo completed.

# depends header
cand.o: cand.h
main.o: cand.h