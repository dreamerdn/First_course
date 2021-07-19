//
//  main.c
//  Laba1_8
//
//  Created by Dasha Neyzhmak on 2/13/21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.


# include <stdio.h>
# include <stdlib.h>
struct customer
{   char surname[4];
    char name[4];
    char patronymic[4];
    char home[4];
    int telephone[4];
    int card[4];
    //struct customer *next;
};

//создание списка
typedef struct Node
{
    struct customer value;
    struct Node *next;
} Node;

//вставляет первым элемент списка
void push(Node **head, struct customer data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

//извлекает элемент списка
struct customer pop(Node **head) {
    Node* prev = NULL;
    struct customer val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

//получение n-го элемента списка
Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

//получение последнего элемента списка
Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

//????
Node* getLastButOne(Node* head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}

//удаление n-го элемента списка
struct customer deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        struct customer val = elm->value;
 
        prev->next = elm->next;
        free(elm);
        return val;
    }
}

//удалить полностью список
void deleteList(Node **head) {
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

/*void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}*/

//из массива в список
void fromArray(Node **head, int *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}

int main()
{
    struct customer dora;
    
    printf("Enter a name");
    for (int i = 0; i<4; i++) {
        scanf("%c", &dora.name[i]);
    }
    printf("Enter a surname");
    for (int i = 0; i<4; i++) {
        scanf("%c", &dora.surname[i]);
    }
    printf("Enter a patr");
    for (int i = 0; i<4; i++) {
        scanf("%c", &dora.patronymic[i]);
    }
    printf("Enter a home");
    for (int i = 0; i<4; i++) {
        scanf("%c", &dora.home[i]);
    }

   /* printf("Enter a card number");
    for (int i = 0; i<4; i++) {
        scanf("%d", &dora.card[i]);}
    
    printf("Enter a tel number");
    for (int i = 0; i<4; i++) {
        scanf("%d\n", &dora.telephone[i]);}*/
    
    Node* head = NULL;
    push(&head,dora);
    
    
}



/*typedef struct customer CustNode;
typedef CustNode *CustNodePtr;

void insert (CustNodePtr*, char);
//char del (CustNodePtr*, char);
int IsEmpty (CustNodePtr);
void printList (CustNodePtr);
void instructions (void);
 
int main ()
{
    CustNodePtr start = NULL;
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
            scanf("%s",&elem);
            insert(&start,elem);
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

 //ввод
   void insert ( CustNodePtr (*s), char value)
    {
        CustNodePtr newP, previous, current;
        newP = (CustNodePtr) malloc (sizeof(CustNode));
 
    if (newP!=NULL)
    {
        newP->surname=value;
        newP->next=NULL;
        previous=NULL;
        current=*s;
        while (current!=NULL && value >current->surname)
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
        {
            temp=*s;
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
 
int IsEmpty(CustNodePtr s)
    {
        return s==NULL;
    }
 
 
 
void printList (CustNodePtr current)
    {
            if (current==NULL)
            printf("The list is empty.In");
            else
            {   printf("The list is :\n");
                while (current!=NULL)
                {   printf("%c-->",current->surname);
                    current=current->next;
                }
                printf("NULL\n");
            }
    }*/
