#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    int book_id;
    char book_name[30];
    int pub_date;
    char auth_name[30];
    char auth_email[30];
};
typedef struct Book Book;

int add_book(Book *book_list, int *num_total_book, int index);
int search_book(Book *book_list, int num_total_book);
int update_book(Book *book_list, int *num_total_book, int index);
int print_book_list(Book *book_list, int num_total_book);
int remove_all(Book *book_list, int index);

int compare_int(int int1, int int2);
int compare_char(char *str1, char *str2);

int main()
{
    int user_choice;
    int num_total_book = 0;
    int index = 0;
    int book_id = 0;
    int pub_date = 0;
    Book *book_list;
    printf("Enter the max amounts of book.");
    scanf("%d", &user_choice);
    book_list = (Book *)malloc(sizeof(Book) * user_choice);

    while(1){
        printf("----------Book management program----------\n");
        printf("Choose the menu\n");
        printf("1.Add the book info\n");
        printf("2.Search the book info\n");
        printf("3.Update the book info\n");
        printf("4.Display a list of all books.\n");
        printf("5.Delete all info.\n");
        printf("6.Shut down the program.\n");

        printf("Choose the nubmer what you want: ");
        scanf("%d", &user_choice);
        if(user_choice == 1)
        {
            index = num_total_book;
            add_book(book_list, &num_total_book, index);
        }
        else if(user_choice == 2)
        {
            search_book(book_list, num_total_book);
        }
        else if(user_choice == 3)
        {
            index = num_total_book;
            update_book(book_list, &num_total_book, index);
        }
        else if(user_choice == 4)
        {
            print_book_list(book_list, num_total_book);
        }
        else if(user_choice == 5)
        {
            index = num_total_book;
            remove_all(book_list, index);
        }
        else if(user_choice == 6)
        {
            break;
        }
    }
    free(book_list);
    return 0;
}

int add_book(Book *book_list, int *num_total_book, int index)
{
    printf("The ID of book: ");
    scanf("%d", &book_list[*num_total_book].book_id);
    int i, c=0;
	for(i=0; i<index; i++)
    {
		while(book_list[*num_total_book].book_id == book_list[i].book_id)
        {
			printf("duplicate id\n");
			printf("Enter the student id:");
            scanf("%d", &book_list[*num_total_book].book_id);
			getchar();
			c++;
			if(c == 3)
				break;
	    }
    }

    printf("The name of book: ");
    scanf("%s", book_list[*num_total_book].book_name);

    printf("The published date: ");
    scanf("%d", &book_list[*num_total_book].pub_date);

    printf("The name of author: ");
    scanf("%s", book_list[*num_total_book].auth_name);

    printf("The email address of author: ");
    scanf("%s", book_list[*num_total_book].auth_email);

    printf("ADDED SUCESSFULLY\n");
    (*num_total_book)++;

    return 0;
}

int search_book(Book *book_list, int num_total_book)
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
            if(compare_int(book_list[i].book_id, user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s\n",
                book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
                book_list[i].auth_name, book_list[i].auth_email);
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
            if(compare_char(book_list[i].book_name, user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s\n",
                book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
                book_list[i].auth_name, book_list[i].auth_email);
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
            if(compare_int(book_list[i].pub_date, user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s\n",
                book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
                book_list[i].auth_name, book_list[i].auth_email);
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
            if(compare_char(book_list[i].auth_name, user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s\n",
                book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
                book_list[i].auth_name, book_list[i].auth_email);
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
            if(compare_char(book_list[i].auth_email, user_search))
            {
                printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s\n",
                book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
                book_list[i].auth_name, book_list[i].auth_email);
            }
        }

    }
    return 0;
}

int compare_int(int int1, int int2)
{
    while(int1)
    {
        if(int1 != int2)
        {
            return 0;
        }
    

    int1++;
    int2++;
    }

    if(int2 == '\0') return 1;

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

int update_book(Book *book_list, int *num_total_book,int index)
{
    int i;
    int user_search;
    int decision;
    int update_decision;
    char str;
    int num;
    printf("Enter the ID to Search:");
    scanf("%d", &user_search);
    for(i = 0; i < index; i++)
    {
        if(compare_int(book_list[i].book_id, user_search))
        {
            printf("ID: %d // Name: %s // Published date: %d // Author name: %s // Author email: %s",
            book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
            book_list[i].auth_name, book_list[i].auth_email);
        }
    }
    printf("\nDo you want to update the information of book? 1:Yes 2:No");
    scanf("%d", &decision);
    if(decision == 1)
    {
        printf("Which one do want to update?\n");
        printf("1.Book Id\n");
        printf("2.Book Name\n");
        printf("3.Published Date\n");
        printf("4.Author Name\n");
        printf("5.Author_Email\n");
        scanf("%d", &update_decision);
        if(update_decision == 1)
        {
            printf("Please, enter the ID to change: ");
            scanf("%d", &num);
            book_list[i].book_id = num;
            printf("Modified completed.\n");
        }
        else if(update_decision == 2)
        {
            printf("Please, enter the book NAME to change: ");
            scanf("%s", book_list[i].book_name);
            printf("Modified completed.\n");


        }
        else if(update_decision == 3)
        {
            printf("Please, enter the published DATE to change: ");
            scanf("%d", &num);
            book_list[i].pub_date = num;
            printf("Modified completed.\n");

        }
        else if(update_decision == 4)
        {
            printf("Please, enter the author NAME to change: ");
            scanf("%s", book_list[i].auth_name);
            printf("Modified completed.\n");
        }
        else if(update_decision == 5)
        {
            printf("Please, enter the author email to change: ");
            scanf("%s", book_list[i].auth_email);
            printf("Modified completed.\n");
        }
    }
    else
    {
        printf("okay bye");
    }
    
return 0;
}

int print_book_list(Book *book_list, int total_num_book)
{
    FILE *fp = fopen("book_list.txt", "w");
    int i;

    if(fp == NULL)
    {
        printf("Error ! \n");
        return -1;
    }

    fprintf(fp, "Book id / Book name / Published date / Author name / Author email\n");
    for (i = 0; i < total_num_book; i++)
    {
        fprintf(fp, "%d / %s / %d / %s / %s",
        book_list[i].book_id, book_list[i].book_name, book_list[i].pub_date, 
        book_list[i].auth_name, book_list[i].auth_email);
        
    }
    fclose(fp);
}

int remove_all(Book *book_list, int index)
{
    int i;
    for(i=0; i<index; i++)
    {
        book_list[i].book_id = "";
        strcpy(book_list[i].book_name, "");
        book_list[i].pub_date = "";
        //strcpy(book_list[i].auth_name = "");
        //strcpy(book_list[i].auth_email = "");
    }
}