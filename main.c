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
    int idd,status=0,iddd;
    ListNode *ptr;
    char bookname_value[100]; // char entered by user
    int id_value;
    char author_value[100];
    float price_value;
    int num,i;
    start();
    welcomeMessage();
    headMessage("MAIN MENU");
    unsigned int choice;
    do {
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Delete Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Search Book");
        printf("\n\t\t\t5.Reset the program");
        printf("\n\t\t\t6.Update book");
        printf("\n\t\t\t7.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\t\t\tHow many of books you want to insert: ");
            scanf("%d",&num);
            for(i=0; i<num; ++i)
            {
                headMessage ("ADD NEW BOOKS");
                printf ("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
                printf ("\n\t\t\t---------------------------------------------------------------------------\n");
                do{
                printf("\n\t\t\tBook Name: ");
                fflush(stdin);
                gets(bookname_value);
                status=isNameValid(&bookname_value);
                if(!status){
                    printf("\n\t\t\tName contains invalid character. Please enter again.");

                }
                }while(!status);

                printf("\n\t\t\tBook ID NO: ");
                scanf("%d",&id_value);
                do{
                printf("\n\t\t\tAuthor Name: ");
                fflush(stdin);
                gets(author_value);
                status=isNameValid(&author_value);
                if(!status){
                    printf("\n\t\t\tName contains invalid character. Please enter again.");
                }
                }while(!status);
                printf("\n\t\t\tPrice: ");
                scanf("%f",&price_value);
                insert(&startPtr, bookname_value,id_value,author_value,price_value); // insert item in list
                printf("\n\t\t\t\t ------------BOOK INSERTED----------\n");
            }
            break;
        case 2: // delete an element
// if list is not empty
            if (!isEmpty(startPtr))
            {
                printf("%s", "Enter id to be deleted: ");
                scanf("\n%d", &id_value);

// if character is found, remove it
                if (delete(&startPtr, id_value))   // remove item
                {
                    printf("\n\t\t\tBook of id %d deleted.\n", id_value);
// printList(startPtr);
                }
                else
                {
                    printf("\n\t\t\t%d not found.\n", id_value);
                }
            }
            else
            {
                puts("\n\t\t\tList is empty.\n");
            }

            break;

        case 3:
            displayAll(startPtr);
            break;
        case 4:
            ptr = malloc(sizeof(ListNode));
            displayQuery(ptr);
            break;
        case 5:
            Reset();
            break;
        case 6:
            printf("\n\t\t\tEnter Id of the book: ");
            scanf("%d",&iddd);
            update(iddd);
            break;
        default:
            puts("\n\t\t\tInvalid choice.\n");
            break;

        printf("\n\t\t\tYour choice: ");
        scanf("%u", &choice);
        }
    }while(choice!=7);
    save();
    puts("\n\t\t\tEnd of run.");
}



// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}
// print the list

void update (int id)
{

  ListNodePtr current = startPtr;
  while (current != NULL)
    {

      if (current->l.id == id)
	{
	  printf ("\n\t\t\tRecord with ID number %d Found !!!\n", id);
	  printf ("\n\t\t\tEnter new book_name: ");
	  scanf ("%s", current->l.bookname);
	  printf ("\n\t\t\tEnter new author_name: ");
	  scanf ("%s", current->l.author);
	  printf ("\n\t\t\tEnter new price: ");
	  scanf ("%f", &current->l.price);
	  printf ("\n\t\t\tData has been updated successfully!!!!\n");
	  return;
	}
      current = current->nextPtr;

    }
  printf ("\n\t\t\tbook with ID number %d is not found !!!\n", id);
}

