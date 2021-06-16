#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
typedef struct list
{
    char bookname[100];
    int id;
    char author[100];
    float price;
} List;
struct listNode
{
    List l;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

int isEmpty(ListNodePtr sPtr);
void update (int id);

int main(void)
{
    int status=0,idd;
    ListNode *ptr;
    char bookname_value[100]; // char entered by user
    int id_value;
    char author_value[100];
    float price_value;
    int num,i;
    welcomeMessage();
    start();
    unsigned int choice;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books.");
        printf("\n\t\t\t2.Delete Books.");
        printf("\n\t\t\t3.View Books.");
        printf("\n\t\t\t4.Search Book");
        printf("\n\t\t\t5.Clear the books data.");
        printf("\n\t\t\t6.Update book.");
        printf("\n\t\t\t7.Exit.");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            headMessage ("ADD NEW BOOKS");
                printf ("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
                printf ("\n\t\t\t---------------------------------------------------------------------------\n");
            printf("\n\t\t\tHow many of books you want to insert: ");
            scanf("%d",&num);
            system("cls");
            for(i=0; i<num; ++i)
            {
                headMessage ("ADD NEW BOOKS");
                printf ("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
                printf ("\n\t\t\t---------------------------------------------------------------------------\n");
                do
                {
                    printf("\n\t\t\tBook Name: ");
                    fflush(stdin);
                    gets(bookname_value);
                    status=isNameValid(&bookname_value);
                    if(!status)
                    {
                        printf("\n\t\t\tName contains invalid character. Please enter again.");

                    }
                }
                while(!status);
                printf("\n\t\t\tBook ID NO: ");
                scanf("%d",&id_value);
                do
                {
                    printf("\n\t\t\tAuthor Name: ");
                    fflush(stdin);
                    gets(author_value);
                    status=isNameValid(&author_value);
                    if(!status)
                    {
                        printf("\n\t\t\tName contains invalid character. Please enter again.");
                    }
                }
                while(!status);
                printf("\n\t\t\tPrice: ");
                scanf("%f",&price_value);
                insert(&startPtr, bookname_value,id_value,author_value,price_value); // insert item in list
                printf("\n\n\t\t\t BOOK INSERTED\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 2: // delete an element
// if list is not empty
            system("cls");
            headMessage("DELETE BOOKS");
            if (!isEmpty(startPtr))
            {
                printf("%s", "\n\t\t\tEnter id to be deleted: ");
                scanf("\n%d", &id_value);

// if character is found, remove it
                if (delete(&startPtr, id_value))   // remove item
                {
                    system("cls");
                    headMessage("DELETE BOOKS");
                    printf("\n\t\t\tBook of id %d deleted.\n", id_value);
// printList(startPtr);
system("pause");
system("cls");
                }
                else
                {
                    //printf("\n\t\t\t%d not found.\n", id_value);
                    system("cls");
                    headMessage("DELETE BOOKS");
                    printf("\n\n\t\t\tId No.%d not found.\n", id_value);
system("pause");
system("cls");
                }
            }
            else
            {
                system("cls");
                    headMessage("DELETE BOOKS");
                puts("\n\t\t\tList is empty.\n");
                system("pause");
                system("cls");
            }

            break;

        case 3:
            displayAll(startPtr);
            break;
        case 4:
            search();
            break;
        case 5:
            Reset();
            break;
        case 6:
            update();
            break;
            case 7:
           save();
    system("cls");
    exitMessage();
    exit(1);
            break;
        default:
            puts("\n\t\t\tInvalid choice.\n");
            system("pause");
            break;
        }
    }
    while(1);
}



