#include <stdio.h>

int add_book(int *book_id, char (*book_name)[30], int *pub_date, char(*auth_name)[30], char(*auth_email)[30], int *num_total_book);
int search_book(int *book_id, char (*book_name)[30], int *pub_date, char(*auth_name)[30], char(*auth_email)[30], int num_total_book);

int compare_int(int *int1, int *int2);
int compare_char(char *str1, char *str2);

int main(){
    int user_choice;
    int num_total_book, book_id, pub_date = 0;
    char book_name[100][30], auth_name[100][30], auth_email[100][30];

    while(1){
        printf("----------Book management program----------\n");
        printf("Choose the menu\n");
        printf("1.Add the book info\n");
        printf("2.Search the book info\n");
        printf("3.Update the book info\n");
        printf("4.Display alist of all books.\n");
        printf("5.Delete all info.\n");
        printf("6.Shut down the program.\n");

        printf("Choose the nubmer what you want: ");
        scanf("%d", &user_choice);
        if(user_choice == 1)
        {
            add_book(&book_id, book_name, &pub_date, auth_name, auth_email, &num_total_book);
        }
        else if(user_choice == 2)
        {
            search_book(&book_id, book_name, &pub_date, auth_name, auth_email, num_total_book);

        }
        else if(user_choice == 3)
        {
            printf("HEllo");
        }
        else if(user_choice == 4)
        {

        }
        else if(user_choice == 5)
        {

        }
        else if(user_choice == 6)
        {
            break;

        }
    }
    return 0;

}

int add_book(int *book_id, char (*book_name)[30], int *pub_date, char (*auth_name)[30], char (*auth_email)[30], int *num_total_book)
{
    printf("The ID of book: ");
    scanf("%d", &book_id[*num_total_book]);

    printf("The name of book: ");
    scanf("%s", book_name[*num_total_book]);

    printf("The published date: ");
    scanf("%d", &pub_date[*num_total_book]);

    printf("The name of author: ");
    scanf("%s", auth_name[*num_total_book]);

    printf("The email address of author: ");
    scanf("%s", auth_email[*num_total_book]);

    printf("ADDED SUCESSFULLY\n");
    (*num_total_book)++;

    return 0;
}

int search_book(int *book_id, char (*book_name)[30], int *pub_date, char (*auth_name)[30], char (*auth_email)[30], int num_total_book)
{
    int user_input;
    int i;

    printf("------------How do you want to search------------");
    printf("\n1.The ID of the book.");
    printf("\n2.The name of the book.");
    printf("\n3.The published date.");
    printf("\n4.The name of the author.");
    printf("\n5.The email address of author.");
    scanf("%d", &user_input);

    if(user_input == 1)
    {
        int user_search;
        printf("Enter the ID to Search:");
        scanf("%d", &user_search);
        for(i = 0; i< num_total_book; i++)
        {
            if(compare_int(&book_id[i], &user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
                book_id[i], book_name[i], pub_date[i], auth_name[i], auth_email[i]);
            }
        }

    }
    else if(user_input == 2)
    {
        char user_search[30];
        printf("Enter the Book name to Search:");
        scanf("%s", user_search);
        for(i = 0; i< num_total_book; i++)
        {
            if(compare_char(book_name[i], user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
                book_id[i], book_name[i], pub_date[i], auth_name[i], auth_email[i]);
            }
        }

    }
    else if(user_input == 3)
    {
        int user_search;
        printf("Enter the published date to Search:");
        scanf("%d", &user_search);
        for(i = 0; i< num_total_book; i++)
        {
            if(compare_int(&pub_date[i], &user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
                book_id[i], book_name[i], pub_date[i], auth_name[i], auth_email[i]);
            }
        }

    }
    else if(user_input == 4)
    {
        char user_search[30];
        printf("Enter the author name to Search:");
        scanf("%s", user_search);
        for(i = 0; i< num_total_book; i++)
        {
            if(compare_char(auth_name[i], user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
                book_id[i], book_name[i], pub_date[i], auth_name[i], auth_email[i]);
            }
        }

    }
    else if(user_input == 4)
    {
        char user_search[30];
        printf("Enter the author email to Search:");
        scanf("%s", user_search);
        for(i = 0; i< num_total_book; i++)
        {
            if(compare_char(auth_email[i], user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
                book_id[i], book_name[i], pub_date[i], auth_name[i], auth_email[i]);
            }
        }

    }
    return 0;
}

int compare_int(int *int1, int *int2)
{
    while(*int1)
    {
        if(*int1 != *int2)
        {
            return 0;
        }
    

    int1++;
    int2++;
    }

    if(*int2 == '\0') return 1;

    return 0;
}

int compare_char(char *str1, char *str2)
{
    while(*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }
    

    str1++;
    str2++;
    }

    if(*str2 == '\0') return 1;

    return 0;
}

int update_book(int *book_id, char (*book_name)[30], int *pub_date, char (*auth_name)[30], char (*auth_email)[30], int num_total_book)
{

}
