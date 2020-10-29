lab6:	main.o myFile.o  
		gcc main.c myFile.c -o lab6

main.o: main.c myFile.c
		gcc -c main.c

myFile.o: myFile.c myLib.h
		gcc -c myFile.c


run:
	./lab6 teste.zip
clear:
	rm -rf *.exe
	rm -rf *.o