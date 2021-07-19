//
//  main.c
//  1_6


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Schoolboy
{   char surname1[10];
    char name1[10];
    char patronymic1[10];
    char class1[10];
    char telephone1[10];
    int average_score1;
    struct Schoolboy *next;
};

typedef struct Schoolboy ListNode;
typedef ListNode *ListNodePtr;
 
//прототипы функций
void printList (ListNodePtr sch);
int check(ListNodePtr sPtr);
void countList(ListNodePtr sPtr);
void counting_el (ListNodePtr* sPtr);
void findMax(ListNodePtr sPtr);
void insert(ListNodePtr* head,char* surname,char* name,char* patronymic,char* home,char* telephone, int average_score);
void findMin(ListNodePtr sPtr);
void deleteList(ListNodePtr *sPtr);
int deleteDouble(ListNodePtr* sPtr);


int main(int argc, const char * argv[])
{
    ListNodePtr startPtr = NULL;
 
    int n;
    char surname[10];
    char name[10];
    char patronymic[10];
    char class[10];
    char telephone[10];
    int average_score = 0;

    while(1)
    {   printf("1 Data input\n");
        printf("2 Data output\n");
        printf("3 Counting the number of items\n");
        printf("4 Finding min\n");
        printf("5 Finding max\n");
        printf("6 Removing repetitions\n");
        printf("7 Deleting all data\n");
        printf("8 Exiting the program\n");
        
        printf("\n Choose n: ");
        
        scanf("%d",&n);
        
        switch (n)
        {
            case 1:
            {
                    printf("Surname: ");
                    gets(surname);
                    gets(surname);
                    printf("Name: ");
                    gets(name);
                    printf("Patronymic: ");
                    gets(patronymic);
                    printf("Class: ");
                    gets(class);
                    printf("Telephone: ");
                    gets(telephone);
                    printf("Average score: ");
                    scanf("%d",&average_score);
                
                insert(&startPtr, surname, name, patronymic, class, telephone, average_score);
                break;
            }
                
            case 2: printList(startPtr);
                break;
            //подсчет количества элементов
            case 3: counting_el(&startPtr);
                break;
            case 4: findMin(startPtr);
                break;
            case 5: findMax(startPtr);
                break;
            case 6: deleteDouble(&startPtr);
                break;
            case 7: deleteList(&startPtr);
                break;
            case 8: return 0;
                
            default: printf("Неверный выбор");
            
        }
    }
    
    return 0;
}
//вывод введенной информации на экран
void printList (ListNodePtr sch)
{
        if (sch==NULL)
        printf("The list is empty.\n");
        else
        {   printf("The list is :\n");
            while (sch!=NULL)
            {   printf("1. %s\n",sch->surname1);
                printf("2. %s\n",sch->name1);
                printf("3. %s\n",sch->patronymic1);
                printf("4. %s\n",sch->class1);
                printf("5. %s\n",sch->telephone1);
                printf("7. %d\n",sch->average_score1);
                printf("\n");
                sch=sch->next;
            }
            printf("NULL\n");
        }
}

int check(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

//ввод данных
void insert(ListNodePtr* head,char* surname,char* name,char* patronymic,char* home,char* telephone, int average_score)
{
    ListNodePtr newPtr, currentPtr;
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    
    if ((newPtr != NULL))
    {
        strcpy(newPtr->surname1,surname);
        strcpy(newPtr->name1,name);
        strcpy(newPtr->patronymic1,patronymic);
        strcpy(newPtr->class1,home);
        strcpy(newPtr->telephone1,telephone);
        newPtr->average_score1 = average_score ;
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

//подсчет количества записей
void countList(ListNodePtr sPtr)
{
    
    int cnt = 0;
    while (sPtr != 0)
        {
            sPtr=sPtr->next;
            cnt++;
        }
    printf("%d\n", cnt);

}

void counting_el (ListNodePtr* sPtr)
{
    
    if (check(*sPtr))
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("Number of list items: \n");
        countList(*sPtr);
        
    }

}

//нахождение максимального среднего балл
void findMax(ListNodePtr sPtr)
    {

        ListNodePtr current = sPtr;
        int max = sPtr->average_score1;
        while (current != NULL)
            {
                if (current->average_score1 > max)
                    {
                        max = current->average_score1;
                    }
                current = current->next;
            }
        printf("Max:%d \n",max);
        
    }
//нахождение минимального среднего балл
void findMin(ListNodePtr sPtr)
    {
        ListNodePtr current = sPtr;
        int min = sPtr->average_score1;
        while (current != NULL)
            {
                if (current->average_score1 < min)
                    {
                        min = current->average_score1;
                    }
                current = current->next;
            }
        printf("Min:%d \n",min);
    }

//удаление повторяющихся записей (полностью повторяются все 7 пунктов)
int deleteDouble(ListNodePtr* sPtr)
{
    ListNodePtr current = *sPtr, start = *sPtr;
    ListNodePtr tempPtr = NULL, prevPtr = NULL;
    while (start != NULL)
        {
            prevPtr = start;
            current = start->next;
            while (current != NULL)
               {
                    if ((current->average_score1== start->average_score1) && (strcmp(current->surname1, start->surname1) == 0) && (strcmp(current->name1, start->name1) == 0) && (strcmp(current->patronymic1, start->patronymic1) == 0) && (strcmp(current->class1, start->class1) == 0) && (strcmp(current->telephone1, start->telephone1) == 0) )
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


//удаление всей введенной информации
void deleteList(ListNodePtr *sPtr)
{
    ListNodePtr current = *sPtr;
    while (current != NULL)
        {
            current = current->next;
            free(*sPtr);
            *sPtr = current;
        }
}
