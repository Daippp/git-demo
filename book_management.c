#include "book_management.h"
extern BookList bk;
int cnt=0;
int booksum=0;
int print_except_number(char filename[],int minnum,int maxnum,char tip[]);
int stoi(char s[]){
    int ret=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9') 
            return -1;
        ret=ret*10+s[i]-'0';
    }
    return ret;
}

void initbook(Book* b,int id,char* title,char* authors,int year,int copies){
    b->id=id;
    b->title = malloc(sizeof(char)*(strlen(title)-1));
    strcpy(b->title,title);
    b->authors = malloc(sizeof(char)*(strlen(authors)-1));
    strcpy(b->authors,authors);
    b->year=year;
    b->copies=copies;
    b->next=NULL;
}

int store_books(FILE *file){
    if(file==NULL) return -1;
    Book* p=bk.list->next;
    fprintf(file,"%d\n",booksum);

    while(p){
        for(int i=0;i<strlen(p->authors);i++)
            if(p->authors[i]==' ') p->authors[i]='_';
        for(int i=0;i<strlen(p->title);i++)
            if(p->title[i]==' ')    p->title[i]='_';
        fprintf(file,"%d %s %s %d %d\n",p->id,p->title,p->authors,p->year,p->copies);

        p=p->next;
    }
    return 0;
}

int load_books(FILE *file){
    if(file==NULL) return -1;
    char c;
    int id,copies,year,i;
    char title[100],author[100],cop[100];
    int len=0;
    bk.list = malloc(sizeof(Book));
    Book* p=bk.list;
    fscanf(file,"%d",&booksum);
    
    for(i=0;i<booksum;i++){
        fscanf(file,"%d%s%s%d%d",&id,title,author,&year,&copies);
        //fgets(cop,255,file);
        //copies=stoi(cop);
        printf("%d\n",cnt);
        fgetc(file);
        if(id>cnt)  cnt=id;
        if(id<0||year<0||copies<0){
            return -2;
        }
        p->next=malloc(sizeof(Book));
        p=p->next;
        p->next=0;
        len++;
        p->id=id;
        p->year=year;
        p->copies=copies;
        p->title=malloc(sizeof(char)*(strlen(title)+1));
        strcpy(p->title,title);
        for(int i=0;i<strlen(p->title);i++){
            if(p->title[i]=='_')    p->title[i]=' ';
        }
        p->authors=malloc(sizeof(char)*(strlen(author)+1));
        strcpy(p->authors,author);
        for(int i=0;i<strlen(p->authors);i++)
            if(p->authors[i]=='_') p->authors[i]=' ';
    }
    bk.length=len;
    bk.list->id=-1;
    return 0;
}

int add_book(Book book){
    Book *p=bk.list->next,*q=bk.list;
    while(p&&book.id>p->id){
        p=p->next;
        q=q->next;
    }
    booksum++;
    q->next=malloc(sizeof(Book));
    q=q->next;
    q->next=p;
    q->id = book.id;
    q->year=book.year;
    q->copies = book.copies;
    q->title=malloc(sizeof(char)*(strlen(book.title)+1));
    strcpy(q->title,book.title);
    q->authors=malloc(sizeof(char)*(strlen(book.authors)+1));
    strcpy(q->authors,book.authors);

    return 0;
}

int remove_book(Book book){
    Book *p=bk.list->next,*q=bk.list;
    while(p&&book.id>p->id){
        p=p->next;
        q=q->next;
    }
    if(p==NULL) return -1;
    q->next=p->next;
    free(p);
    return 0;
}

BookList find_book_by_title (const char *title){
    BookList ret;
    ret.list=malloc(sizeof(Book));
    Book *r=ret.list;
    ret.list->next=NULL;
    Book *p=bk.list->next;
    while(p){
        if(strcmp(p->title,title)==0){
            r->next=malloc(sizeof(Book));
            r=r->next;
            r->next=NULL;
            r->id = p->id;
            r->year=p->year;
            r->copies = p->copies;

            r->title=malloc(sizeof(char)*(strlen(p->title)+1));
            strcpy(r->title,p->title);
            r->authors=malloc(sizeof(char)*(strlen(p->authors)+1));
            strcpy(r->authors,p->authors);
            p=p->next;
        }
    }
    return ret;
}

int findbookbyid(int id){
    Book *p=bk.list->next;
    while(p){
        if(id==p->id){
            return 1;
        }
        p=p->next;
    }
    return 0;
}

BookList find_book_by_author (const char *author){
    BookList ret;
    ret.list=malloc(sizeof(Book));
    Book *r=ret.list;
    ret.list->next=NULL;
    Book *p=bk.list->next;
    while(p){
        if(strcmp(p->authors,author)==0){
            r->next=malloc(sizeof(Book));
            r=r->next;
            r->next=NULL;
            r->id = p->id;
            r->year=p->year;
            r->copies = p->copies;

            r->title=malloc(sizeof(char)*(strlen(p->title)+1));
            strcpy(r->title,p->title);
            r->authors=malloc(sizeof(char)*(strlen(p->authors)+1));
            strcpy(r->authors,p->authors);
            p=p->next;
        }
    }
    return ret;
}

BookList find_book_by_year (unsigned int year){
    BookList ret;
    ret.list=malloc(sizeof(Book));
    Book *r=ret.list;
    ret.list->next=NULL;
    Book *p=bk.list->next;
    while(p){
        if(p->year==year){
            r->next=malloc(sizeof(Book));
            r=r->next;
            r->next=NULL;
            r->id = p->id;
            r->year=p->year;
            r->copies = p->copies;

            r->title=malloc(sizeof(char)*(strlen(p->title)+1));
            strcpy(r->title,p->title);
            r->authors=malloc(sizeof(char)*(strlen(p->authors)+1));
            strcpy(r->authors,p->authors);
            p=p->next;
        }
    }
    return ret;
}

void displayone (Book *b){
    printf("%5d %-45s %-45s %5d %-5d\n",b->id,b->title,b->authors,b->year,b->copies);
    return;
}

void displayall(BookList bk){
    printf("\n");
    printf("%5s %-45s %-45s %5s %-5s\n","ID","Title","Authors","Year","Copies");
    for(Book* p=bk.list->next;p;p=p->next){
        displayone(p);
    }
    printf("\n");
    return;
}

void searchbook(){
    char filename[100]="..\\display\\search.txt";
    int option = print_except_number(filename,1,4,"\nSorry, the option you entered was invalid, please try again.\n");
    char key[1000];
    int t;
    BookList h;
    switch(option){
        case 1:
            printf("Please enter title: ");
            scanf("%s",key);
            h=find_book_by_title(key);
            break;
        case 2:
            printf("Please enter author: ");
            scanf("%s",key);
            h=find_book_by_author(key);
            break;
        case 3:
            printf("Please enter year: ");
            scanf("%s",key);
            t=stoi(key);
            if(t==-1){
                printf("\nInvalid key.\n");
                return;
            }
            h=find_book_by_year(t);
            break;
        case 4:
            return;
    }
    displayall(h);
    return;
}

void addbook(){
    char c;
    int id=-1,copies=-1,year=-1;
    char title[100],author[100],cop[100];
    int len=0;
    
    printf("Enter the title of the book you wish to add: ");
    gets(title);
    printf("Enter the author of the book you wish to add: ");
    gets(author);
    printf("Enter the year that the book you wish to add was released: ");
    gets(cop);
    year=stoi(cop);
    printf("Enter the number of copies of the book that you wish to add: ");
    //scanf("%d",&copies);
    gets(cop);
    copies=stoi(cop);
    printf("\n");
    if(year<=0||copies<0){
        printf("Sorry, you attemped to add an invalid book, please try again.\n");
        return ;
    }
    printf("\n");
    Book b;
    //printf("here");
    initbook(&b,++cnt,title,author,year,copies);
    //printf("here");
    add_book(b);
    //printf("here");
    printf("You have add a book sucessfully\n");
    return ;
}

void removebook(){
    char key[100];
    int tmp;
    displayall(bk);
    printf("Enter the ID of the book you wish to remove: ");
    scanf("%s",key);
    tmp=stoi(key);
    if(tmp==-1){
        printf("Invalid ID.");
        return;
    }
    Book *p=bk.list->next;
    Book *q=bk.list;
    while(p){
        if(p->id==tmp){
            q->next=p->next;
            free(p);
        }
        p=p->next;
        q=q->next;
    }
}
