C = gcc
FILE = lde_solver.c

all: lde_solver

lde_solver: lde_solver.o
		$(CC) -o lde_solver lde_solver.o

lde_solver.o: $(FILE)
		$(CC) -c $(FILE)

testcases: lde_solver
	./lde_solver -383 403 -586
	./lde_solver 467 -488 28
	./lde_solver 546 -440 -743
	./lde_solver 620 839 800
	./lde_solver -835 155 -614
	./lde_solver 738 -519 251
	./lde_solver -181 975 621
	./lde_solver 221 622 400
	./lde_solver 349 -199 -78
	./lde_solver -29 64 955
	./lde_solver 206 695 57
	./lde_solver -73 -108 -479
	./lde_solver -590 -112 -15
	./lde_solver 230 848 -132
	./lde_solver -477 -903 760
	./lde_solver 370 -397 591

clean:
	rm lde_solver lde_solver.o
