#include <stdio.h>
#include <string.h>
 
struct Books
{
 int ID;
 char name[20];
 char publisher[200];
};

 
struct Books books[20];
 
int myIndex = 0;

int write(void)
{
    int next = 1;
    FILE *fp = fopen("Book_file.txt","w");

    while(1)
    {
    printf(" \n");
    printf("\nEnter Book ID: ");
    scanf(" %d", &books[myIndex].ID);
    getchar();
 
    printf("\nEnter book name: ");
    gets(books[myIndex].name); //Take string info by using gets()
 
    printf("\nEnter publisher: ");
    gets(books[myIndex].publisher);
    
    myIndex++;
    
    fwrite(&books, sizeof(books),1,fp);
    printf("\nRecord saved\n");
 
    printf("\nWould you like to add another book? \n<< Enter 1 to continue and 0 to exit>> ");
    scanf("%d", &next);
    getchar();
 
    if(next==0) break;
    }
    fclose(fp);
    return 0;

}

int read(void)
{
    int i;
    FILE *fp = fopen("Book_file.txt", "r");
    for(i = 0; i< myIndex; i++)
    {
        fread(&books,sizeof(books),1,fp);
        printf("The id of books is: %d\n",books[i].ID);
        printf("The name of books is: %s\n",books[i].name);
        printf("THe publisher of books is: %s\n",books[i].publisher);
    }
    return 0;
}
int main()
{
    write();
    read();
}