all: StrList

StrList: StrList.o main.o
	gcc -Wall -g -o StrList StrList.o main.o

StrList.o: StrList.c StrList.h
	gcc -Wall -g -c StrList.c -o StrList.o

main.o: main.c StrList.h
	gcc -Wall -g -c main.c -o main.o

clean:
	rm -f *.o StrList
