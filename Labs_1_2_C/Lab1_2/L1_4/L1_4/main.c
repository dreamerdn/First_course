//  main.c
//  1_5

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
struct Reader
{   char name_a[10];
    char nazvanie_a[10];
    int card_number_a;
    int period_a;
    struct Reader *next;
};
 
typedef struct Reader CNode;
typedef CNode *CNodePtr;
 
void Output (CNodePtr sch);
int check(CNodePtr sPtr);
void insert(CNodePtr* head,char* name,char* nazvanie,int card_number,int period);
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
    char nazvanie[10];
    int card_number;
    int period;
 
    while(1)
    {   printf("1 Data input\n");
        printf("2 Outputting data\n");
        printf("3 Counting the number of items\n");
        printf("4 Finding min\n");
        printf("5 Finding max\n");
        printf("6 Remove duplicates\n");
        printf("7 Delete all data\n");
        printf("8 Exit the program\n");
 
        printf("\nChoose n: ");
 
        scanf("%d",&n);
 
        switch (n)
        {
            case 1:
            {
                    printf("Full Name: ");
                    gets(name);
                    gets(name);
                    printf("Name of the book: ");
                    gets(nazvanie);
                    printf("Library card number: ");
                    scanf("%d",&card_number);
                    printf("Return period: ");
                    scanf("%d",&period);
 
                insert(&startPtr, name, nazvanie, card_number, period);
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
                printf("2. %s\n",sch->nazvanie_a);
                printf("3. %d\n",sch->card_number_a);
                printf("4. %d\n",sch->period_a);
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
 

void insert(CNodePtr* head,char* name,char* nazvanie,int card_number,int period)
{
    CNodePtr newPtr, currentPtr;
    newPtr = (CNodePtr)malloc(sizeof(CNode));
 
    if ((newPtr != NULL))
    {
        strcpy(newPtr->name_a,name);
        strcpy(newPtr->nazvanie_a,nazvanie);
        newPtr->card_number_a = card_number;
        newPtr->period_a = period;
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
        int max = sPtr->period_a;
        while (current != NULL)
            {
                if (current->period_a > max)
                    {
                        max = current->period_a;
                    }
                current = current->next;
            }
        printf("Max:%d \n",max);
 
    }
 
void Min(CNodePtr sPtr)
    {
        CNodePtr current = sPtr;
        int min = sPtr->period_a;
        while (current != NULL)
            {
                if (current->period_a < min)
                    {
                        min = current->period_a;
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
                    if ((current->period_a == start->period_a) && (strcmp(current->name_a, start->name_a) == 0) && (strcmp(current->nazvanie_a, start->nazvanie_a) == 0) && (current->card_number_a == start->card_number_a))
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
 

