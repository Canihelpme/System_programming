#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


struct Books
{
 int ID;
 char name[20];
 char publisher[200];
};

 
struct Books books[20];
 
int myIndex = 0;

char bid[10];

int write(void)
{
    int next = 1;
    char ne_xt[10]; memset(ne_xt, '\0', 10);
    FILE *fp = fopen("Book_file.txt","w");

    while(1)
    {

    memset(bid, '\0', 10);

    write(1, " \n", sizeof(" \n"));
    write(1, "\nEnter Book ID: ", sizeof("\nEnter Book ID: "));
    read(0, bid, 10);
    books[myIndex].ID = atoi(bid);

    char name[10];
    memset(name, '\0', 10);

    write(1, "\nEnter book name: ", sizeof("\nEnter book name: "));
    read(0, name, 10);
    strcpy(books[myIndex].name, name);
 
    char publisher[10];
    memset(publisher, '\0', 10);

    write(1, "\nEnter publisher: ", sizeof("\nEnter publisher: "));
    read(0, publisher, 10);
    strcpy(books[myIndex].publisher, publisher);
    
    myIndex++;
    
    fwrite(&books, sizeof(books),1,fp);
    write(1, "\nRecord saved\n", sizeof("\nRecord saved\n"));
 
    write(1, "\nWould you like to add another book? \n<< Enter 1 to continue and 0 to exit>> ",
     sizeof("\nWould you like to add another book? \n<< Enter 1 to continue and 0 to exit>> "));
    read(0, ne_xt, 10);
    next = atoi(ne_xt);
 
    if(next==0) break;
    }
    fclose(fp);
    return 0;

}

int read(struct Books books)
{
    write(1, "\nID: ",sizeof("\nID: "));
    write(1, &bid, sizeof(books.ID));
    write(1, "\nName: ",sizeof("\nName: "));
    write(1, &books.name, sizeof(books.name));
    write(1, "\nPublisher: ", sizeof("\nPublisher: "));
    write(1, &books.publisher, sizeof(books.publisher));
    return 0;
}

int main()
{
    write();
    int i;
    for(i = 0; i < myIndex; i++)
    {
        read(books[i]);
    }
    return 0;
}