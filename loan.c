#include"loan.h"

extern char loanfile[100];
extern char usrname[100];

int blist[100][100];
int bcnt[100];
char bname[100][100];
int bsum;

int findbookbyid(int id);
void loadloan(){
    FILE *f=fopen(loanfile,"r");
    bsum=0;
    int i;
    while(!feof(f)){
        fscanf(f,"%s%d",bname[bsum],&bcnt[bsum]);
        for(i=0;i<bcnt[bsum];i++){
            fscanf(f,"%d",&blist[bsum][i]);
        }
        bsum++;
    }
    bsum--;
    //printf("bsum = %d\n",bsum);
    fclose(f);
}

void save_loan(){
    FILE *f=fopen(loanfile,"w");
    //printf("%d",bsum);
    int i,j;
    for(i=0;i<bsum;i++){
        fprintf(f,"%s %d\n",bname[i],bcnt[i]);
        for(j=0;j<bcnt[i];j++){
            fprintf(f,"%d ",blist[i][j]);
            //printf("writing\n");
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

void borrowbook(){
    int id,i,j;
    char tmp[100];
    printf("Enter the ID of the book you wish to borrow: ");
    gets(tmp);
    id=stoi(tmp);
    for(i=0;i<bsum;i++){
        if(strcmp(bname[i],usrname)==0){
            break;
        }
    }
    if(findbookbyid(id)==0){
        printf("\nInvalid ID\n\n");
        return;
    }

    if(i==bsum){
        bsum++;
        bcnt[i]=0;
        strcpy(bname[i],usrname);
    }
    for(j=0;j<bcnt[i];j++){
        if(blist[i][j]==id){
            printf("\nSorry you have a copy of this book on loan.\n\n");
            return;
        }
    }
    blist[i][bcnt[i]++]=id;
    printf("\nBorrow book successfully.\n\n");
    return;
}

void returnbook(){
    int id,i,j;
    char tmp[100];
    printf("Enter the ID of the book you wish to return: ");
    gets(tmp);
    id=stoi(tmp);
    for(i=0;i<bsum;i++){
        if(strcmp(bname[i],usrname)==0){
            break;
        }
    }
    if(i==bsum){
        printf("\nYou haven't borrow this book.\n");
    }
    for(j=0;j<bcnt[i];j++){
        if(blist[i][j]==id){
            int k=j;
            for(k=j+1;k<bcnt[i];k++)
                blist[i][k-1]=blist[i][k];
            bcnt[i]--;
            printf("\nReturn book successfully.\n\n");
            return;
        }
    }
    printf("\nYou haven't borrow this book.\n\n");
    return;
}