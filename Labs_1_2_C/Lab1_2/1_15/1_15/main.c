//
//  main.c
//  1_15
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
struct cinema
{   char name_a[10];
    char session_a[10];
    int ticket_price_a;
    int quantity_a;
    struct cinema *next;
};
 
typedef struct cinema CNode;
typedef CNode *CNodePtr;
 
void Output (CNodePtr sch);
int check(CNodePtr sPtr);
void insert(CNodePtr* head,char* name,char* session,int ticket_price,int quantity);
void countList(CNodePtr sPtr);
void AmountOfElements (CNodePtr* sPtr);
void Max(CNodePtr sPtr);
void Min(CNodePtr sPtr);
int DoubleDelete(CNodePtr* sPtr);
void DeleteList(CNodePtr *sPtr);
 
int main(int argc, const char * argv[])
{
    CNodePtr startPtr = NULL;
 
    int n;
    char name[10];
    char session[10];
    int ticket_price;
    int quantity;
 
    while(1)
    {   printf("1 Ввод данных\n");
        printf("2 Вывод данных\n");
        printf("3 Подсчет количества элементов\n");
        printf("4 Нахождение min\n");
        printf("5 Нахождение max\n");
        printf("6 Удаление повторений\n");
        printf("7 Удаление всех данных\n");
        printf("8 Выход из программы\n");
 
        printf("\nChoose n: ");
 
        scanf("%d",&n);
 
        switch (n)
        {
            case 1:
            {
                    printf("Movie title: ");
                    gets(name);
                    gets(name);
                    printf("Session: ");
                    gets(session);
                    printf("Ticket price: ");
                    scanf("%d",&ticket_price);
                    printf("Number of viewers: ");
                    scanf("%d",&quantity);
 
                insert(&startPtr, name, session, ticket_price, quantity);
                break;
            }
 
            case 2: Output(startPtr);
                break;
            //подсчет количества элементов
            case 3: AmountOfElements(&startPtr);
                break;
            //нахождение минимального
            case 4: Min(startPtr);
                break;
            //нахождение максимального
            case 5: Max(startPtr);
                break;
            //удаление повторений
            case 6: DoubleDelete(&startPtr);
                break;
            //удаление всего
            case 7: DeleteList(&startPtr);
                break;
            //выход из программы
            case 8: return 0;
            //при неправильном выборе n
            default: printf("Неверный выбор");
 
        }
    }
 
    return 0;
}

void Output (CNodePtr sch)
{
        if (sch==NULL)
        printf("The list is empty.\n");
        else
        {   printf("The list is :\n");
            while (sch!=NULL)
            {   printf("1. %s\n",sch->name_a);
                printf("2. %s\n",sch->session_a);
                printf("3. %d\n",sch->ticket_price_a);
                printf("4. %d\n",sch->quantity_a);
                printf("\n");
                sch=sch->next;
            }
            printf("NULL\n");
        }
}
 
int check(CNodePtr sPtr)
{
    return sPtr == NULL;
}
 
void insert(CNodePtr* head,char* name,char* session,int ticket_price,int quantity)
{
    CNodePtr newPtr, currentPtr;
    newPtr = (CNodePtr)malloc(sizeof(CNode));
 
    if ((newPtr != NULL))
    {
        strcpy(newPtr->name_a,name);
        strcpy(newPtr->session_a,session);
        newPtr->ticket_price_a = ticket_price;
        newPtr->quantity_a = quantity;
        newPtr->next = NULL;
        currentPtr = *head;
            if (currentPtr == NULL)
            {
                *head = newPtr;
            }
                else
                {
                    while (currentPtr->next != NULL)
                    {
                        currentPtr = currentPtr->next;
                    }
                        currentPtr->next = newPtr;
                }
 
    }
 
}
 
void countList(CNodePtr sPtr)
{
 
    int cnt = 0;
    while (sPtr != 0)
        {
            sPtr=sPtr->next;
            cnt++;
        }
    printf("%d\n", cnt);
 
}
 
void AmountOfElements (CNodePtr* sPtr)
{
 
    if (check(*sPtr))
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("Number of list items: ");
        countList(*sPtr);
 
    }
 
}
 
 
void Max(CNodePtr sPtr)
    {
 
        CNodePtr current = sPtr;
        int max = sPtr->quantity_a;
        while (current != NULL)
            {
                if (current->quantity_a > max)
                    {
                        max = current->quantity_a;
                    }
                current = current->next;
            }
        printf("Max:%d \n",max);
 
    }
 
void Min(CNodePtr sPtr)
    {
        CNodePtr current = sPtr;
        int min = sPtr->quantity_a;
        while (current != NULL)
            {
                if (current->quantity_a < min)
                    {
                        min = current->quantity_a;
                    }
                current = current->next;
            }
        printf("Min:%d \n",min);
    }
 
 
int DoubleDelete(CNodePtr* sPtr)
{
    CNodePtr current = *sPtr, start = *sPtr;
    CNodePtr tempPtr = NULL, prevPtr = NULL;
    while (start != NULL)
        {
            prevPtr = start;
            current = start->next;
            while (current != NULL)
               {
                    if ((current->quantity_a == start->quantity_a) && (strcmp(current->name_a, start->name_a) == 0) && (strcmp(current->session_a, start->session_a) == 0) && (current->ticket_price_a == start->ticket_price_a))
                       {
                           tempPtr = current;
                           prevPtr->next = current->next;
                           current = current->next;
                           free(tempPtr);
                           return sPtr == NULL;
                       }
                    else
                       {
                           prevPtr = current;
                           current = current->next;
                       }
                }
            start = start->next;
        }
    return 0;
}
 
void DeleteList(CNodePtr *sPtr)
{
    CNodePtr current = *sPtr;
    while (current != NULL)
        {
            current = current->next;
            free(*sPtr);
            *sPtr = current;
        }
}
 
