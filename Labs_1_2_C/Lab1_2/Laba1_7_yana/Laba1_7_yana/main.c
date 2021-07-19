# include <stdio.h>
# include <stdlib.h>
struct list
{
    char book;
    struct list *next;
};
 
typedef struct list ListNode;
typedef ListNode *ListNodePtr;
void insert (ListNodePtr*, char);
char del (ListNodePtr*, char);
int IsEmpty (ListNodePtr);
void printList (ListNodePtr);
void instructions (void);
 
int main ()
{
    ListNodePtr start = NULL;
    int choice;
    char elem;
    instructions();
    printf("?");
    scanf("%d", &choice);
    while (1)
    {
        switch (choice)
    {
        case 1:
            printf ("Enter an character: ");
            scanf("\n%c", &elem);
            insert(&start, elem);
            printList (start);
            break;
        case 3:
            return 0;
        case 2:
            if (!IsEmpty(start))
            {
                printf("Enter character to be deleted:");
                scanf("\n%c", &elem);
 
                if (del(&start,elem))
                {
                    printf("%c deleted. In", elem);
                    printList(start);
                }
                else
                    printf("%c not found\n", elem);
             }
        else
        printf("List is empty.\n");
        break;
 
        default:
            printf ("Invalid choice. In");
        instructions();
        break;
 
    }
        printf("");
        scanf("%d", &choice);
    }
        return 0;
}
 
 
 void instructions(void)
    {
    printf("Enter choice:\n"
           "1 insert an element into the list.\n"
           "2 delete an element from the list. \n"
           "3 end program\n");
    }
 
   void insert (ListNodePtr (*s), char value)
    {
        ListNodePtr newP, previous, current;
        newP = (ListNodePtr) malloc (sizeof(ListNode));
 
    if (newP!=NULL)
    {
        newP->book=value;
        newP->next=NULL;
        previous=NULL;
        current=*s;
        while (current!=NULL && value >current->book)
        {
            previous=current;
            current=current->next;
        }
 
        if(previous==NULL)
        {
            newP->next=*s;
            *s=newP;
        }
            else
            {
                previous->next = newP;
                newP->next = current;
            }
    }
            else
                printf("%c not inserted. No memory available. \n", value);
        }

char del (ListNodePtr *s, char value)
        {
            ListNodePtr previous, current, temp;
            if (value == (*s)->book)
            { temp=*s;
                *s=(*s)->next;
                free(temp);
                return value;
            }
                else
                {
                    previous=*s;
                    current=(*s)->next;
                    while (current!=NULL && current->book!= value)
                    {
                        previous=current;
                        current=current->next;
                    }
 
                    if (current!=NULL)
                    {
                        temp=current;
                        previous->next=current->next;
                        free(temp);
                        return value;
                    }
 
                    }
                        return '\0';
                    }
 
int IsEmpty(ListNodePtr s)
    {
        return s==NULL;
    }
 
 
 
void printList (ListNodePtr current)
    {
            if (current==NULL)
            printf("The list is empty.In");
            else
            {   printf("The list is :\n");
                while (current!=NULL)
                {   printf("%c-->",current->book);
                    current=current->next;
                }
                printf("NULL\n");
            }
    }
