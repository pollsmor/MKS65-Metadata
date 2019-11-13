all: main.o
	gcc -o stat main.o

main.o: main.c
	gcc -c main.c

run:
	./stat

clean:
	rm *.o
	rm stat
