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

int myindex = 0;

void Fill_Book(char line[], int size)
{
    int init_size = strlen(line);
    char delim[] = ",";

    char *ptr = strtok(line, delim);
    sscanf(ptr, "%d", &books[myindex].ID);

    ptr = strtok(NULL, delim);
    strcpy(books[myindex].name, ptr);

    ptr = strtok(NULL, delim);
    strcpy(books[myindex].publisher, ptr);

    myindex++;
}

void add_booksfromfile()
{
    int fd = open("Shah.txt", O_RDONLY);
    if (fd == -1) perror("FILE ERROR");
    int nread;
    char c;
    char line[50];
    int i = 0;

    printf("\nReading from File\n");
    while (nread = read(fd, &c, 1) > 0)
    {
        line[i] = c;
        i++;
        if (c == ';')
        {
            Fill_Book(line, sizeof(line) / sizeof(line[0]));
            i = 0;
        }
    }
}

void DisplayBooks(struct Books book)
{
    printf("\n           \n");
    printf("\nID %d     ",book.ID);
    printf("\nName %s     ",book.name);
    printf("\nPublisher %s\n     ", book.publisher);
}

int main()
{
    add_booksfromfile();

    int i;
    for(i = 0; i < myindex; i++)
    {
        DisplayBooks(books[i]);
    }
}