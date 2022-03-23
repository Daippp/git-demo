all : main.o usr.o book_management.o
	gcc main.o usr.o book_management.o -o main
main.o : main.c
	gcc main.c -c -o main.o
usr.o : usr.c
	gcc usr.c -c -o usr.o
book_management.o : book_management.c
	gcc book_management.c -c -o book_management.o
clean:
	del *.o main.exe -rf