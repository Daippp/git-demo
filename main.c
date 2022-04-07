#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"book_management.h"
#include"usr.h"
#include"loan.h"

char usrname[100];
char usrfile[100]={"..//data//usr.txt"};
char bookfile[100]={"..//data//books.txt"};
char loanfile[100]={"..//data//loans.txt"};
int stat=0;
BookList bk;
extern void login();

//append a int to string
void numcat(char* s,int x){
    int len=strlen(s);
    s[len]=x+'0';
    s[len+1]='\0';
}

//read file and print to screen
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

const char str[5][1000]={
	"\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for Books\n4) Display all books\n5) Quit\n  option: ",
	"\nPlease choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ",
	"\nPlease choose an option:\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ",
	"Please choose an option:\n1) Find books by title\n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: "
};

int print_except_number(int id,int minnum,int maxnum,char tip[]){
	
    int ret=-1,fst=1;
    char input[100];
    do{
        if(!fst){
            printf("%s",tip);
        }
        else    fst=0;
        printf("%s",str[id]);
        gets(input);
        //scanf("%s",input);
        ret=stoi(input);
    }while(ret<minnum||ret>maxnum);
    
    return ret;
}

int main(int argc,char* argv[]){
    if(argc<3){
        printf("You haven't enter enough arguments.Use default file.\n");
    }
    if(argc>1)  strcpy(bookfile,argv[1]);
    if(argc>2)  strcpy(usrfile,argv[2]);
    if(argc>3)  strcpy(loanfile,argv[3]);

    FILE* store;
    /*FILE* load=fopen(bookfile,"r");
    load_books(load);
    loadloan();
    fclose(load);
*/

    while(1){
        //set filename of tips
       /* char filename[100]="..\\display\\main";
        numcat(filename,stat);
        strcat(filename,".txt");*/

        //get user input option
        int option;
        if(stat!=0) printf("Logged in as: %s",usrname);
        option = print_except_number(stat,1,5,"\nSorry, the option you entered was invalid, please try again.\n");
        fflush(stdin);
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
                searchbook();
                break;
            case 4:
                displayall(bk);
                break;
            case 5:
                printf("Thank you for using the Library!\n");
                if(stat==0){
                    save_loan();
                    store=fopen(bookfile,"w");
                    store_books(store);
                    fclose(store);
                    printf("Goodbye!");
                    return 0;
                }
                else stat=0;
                
        }
    }

    
}
