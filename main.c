#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"book_management.h"

char username[100];
int stat=0;
BookList books;

void print_file(char filename[]){
    return;
}

int print_except_number(char filename[],int minnum,int maxnum,char tip[]){
    return 0;
}



int main(){
    FILE* load=fopen("data\\books.txt","r");
    load_books(load);
    fclose(load);


    while(1){
        char filename[100];
        
    }

    FILE* store=fopen("data\\books.txt","w");
    store_books(store);
    fclose(store);
    return 0;
}




/*
Please choose an option:
1) Register an account
2) Login
3) Search for Books
4) Display all books
5) Quit
*/