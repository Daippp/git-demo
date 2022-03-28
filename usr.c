#include"usr.h"
extern int stat;
extern char usrfile[100];
extern char usrname[100];

int num;
char usr[100][100];
char paswrd[100][100];
int usrstat[100];

void login(){
    char in1[100],in2[100];
    printf("\nPlease enter your username: ");
    gets(in1);
    printf("Please enter your password: ");
    gets(in2);

    //find user in file
    FILE *f=fopen(usrfile,"r");
    if(f){
        num=0;
        while(!feof(f)){
            fscanf(f,"%s%s%d",usr[num],paswrd[num],&usrstat[num]);
            num++;
            fgetc(f);
        }
        fclose(f);

        int i;
        for(i=0;i<num;i++){
            if(strcmp(in1,usr[i])==0){
                if(strcmp(in2,paswrd[i])==0){
                    stat=usrstat[i];
                    strcpy(usrname,in1);
                    printf("\n");
                }
                else{
                    printf("\nWrong passwrd\n");
                }
                    return; 
            }
        }
    }
    printf("User not exist\n");
}

void logout(){
    stat=0;
}

void reg(){
    //register
    char in1[100],in2[100];
    printf("\nPlease enter a username: ");
    gets(in1);
    printf("Please enter a password: ");
    gets(in2);

    FILE *f=fopen(usrfile,"r");
    if(f){
        num=0;
        while(!feof(f)){
            fscanf(f,"%s%s%d",usr[num],paswrd[num],&usrstat[num]);
            fgetc(f);
            num++;
        }
        fclose(f);

        int i;
        for(i=0;i<num;i++){
            if(strcmp(in1,usr[i])==0){
                    printf("\nUser already exist\n");
                    return; 
            }
        }
    }
    printf("\nRegister sucessfully\n");
    f=fopen(usrfile,"w");
    
    for(int i=0;i<num;i++){
        fprintf(f,"%s %s %d\n",usr[i],paswrd[i],usrstat[i]);
    }
    fprintf(f,"%s %s %d",in1,in2,1);
    fclose(f);
}