main:
	gcc -o fsmLogic.o -c mylib/fsmLogic.c
	gcc -o main.out main.c fsmLogic.o
	./main.out

run:
	./main.out
	
clear:
	rm -rf *.out
	rm -rf *.o