#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
    int B_id;
    char B_name[20];
    int Pub_date;
    char A_Name[20];
    char A_Email[20];
};

typedef struct book book;
int main()
{
    FILE *outfile;

    outfile = fopen ("Test.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }

    struct book input1 = {1, "wow", 20200101, "Shah", "gmail"};
    struct book input2 = {2, "hoh", 20200505, "mahindrah", "yahoo"};

    fwrite (&input1, sizeof(struct book), 1, outfile);
    fwrite (&input2, sizeof(struct book), 1, outfile);

    if(fwrite != 0)
        printf("Contents to file written sucessfully!\n");
    else
        printf("Error writing file!\n");
    
    fclose (outfile);

    return 0;
}
