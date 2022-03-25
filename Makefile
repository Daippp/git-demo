all : main.o usr.o book_management.o loan.o
	gcc main.o usr.o book_management.o loan.o -o lib
main.o : main.c
	gcc main.c -c -o main.o
usr.o : usr.c
	gcc usr.c -c -o usr.o
book_management.o : book_management.c
	gcc book_management.c -c -o book_management.o
loan.o : loan.c
	gcc loan.c -c -o loan.o
clean:
	del *.o main.exe -rf