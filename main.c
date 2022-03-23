#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"book_management.h"
#include"usr.h"

char username[100];
int stat=0;
BookList books;

void numcat(char* s,int x){
    int len=strlen(s);
    s[len]=x+'0';
    s[len+1]='\0';
}

void print_file(char filename[]){
    FILE *prt=fopen(filename,"r");
    char buff[255];
    if(prt!=NULL){
        while(!feof(prt)){
            fgets(buff,255,prt);
            printf("%s",buff);
        }
        fclose(prt);
    }
    return;
}

int print_except_number(char filename[],int minnum,int maxnum,char tip[]){
    int ret=-1,fst=1;
    do{
        if(!fst){
            printf("%s",tip);
        }
        else    fst=0;
        print_file(filename);
        scanf("%d",&ret);
    }while(ret<minnum||ret>maxnum);
    
    return 0;
}



int main(){
    FILE* store;
    FILE* load=fopen("..\\data\\books.txt","r");
    load_books(load);
    fclose(load);


    while(1){
        //set filename of tips
        char filename[100]="..\\display\\main";
        numcat(filename,stat);
        strcat(filename,".txt");

        //get user input option
        int option;
        option = print_except_number(filename,1,5,"\nSorry, the option you entered was invalid, please try again.\n");
        
        
        switch(option){
            case 1:
                if(stat==0){
                    reg();
                }
                else if(stat==1){
                    borrowbook();
                }
                else if(stat==2){
                    addbook();
                }
                break;
            case 2:
                if(stat==0){
                    login();
                }
                else if(stat==1){
                    returnbook();
                }
                else if(stat==2){
                    removebook();
                }
                break;
            case 3:
                if(stat==0){
                    reg();
                }
                else{
                    searchbook();
                }
                break;
            case 4:
                displayall();
                break;
            case 5:
                store=fopen("..\\data\\books.txt","w");
                store_books(store);
                fclose(store);
                return 0;
        }
    }

    
}