//
//  main.c
//  1_8
//
//  Created by Dasha Neyzhmak on 2/17/21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct customer
{   char surname1[10];
    char name1[10];
    char patronymic1[10];
    char home1[10];
    char telephone1[10];
    char card1[10];
    int carrd22;
    struct customer *next;
};

typedef struct customer ListNode;
typedef ListNode *ListNodePtr;

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
                printf("4. %s\n",sch->home1);
                printf("5. %s\n",sch->telephone1);
                printf("6. %s\n",sch->card1);
                printf("7. %d\n",sch->card22);
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

void insert(ListNodePtr* head,char* surname,char* name,char* patronymic,char* home,char* telephone,char* card, int card2)
{
    ListNodePtr newPtr, currentPtr;
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    
    if ((newPtr != NULL))
    {
        strcpy(newPtr->surname1,surname);
        strcpy(newPtr->name1,name);
        strcpy(newPtr->patronymic1,patronymic);
        strcpy(newPtr->home1,home);
        strcpy(newPtr->telephone1,telephone);
        strcpy(newPtr->card1,card);
        newPtr->card22 = card2 ;
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


void findMax(ListNodePtr sPtr)
    {

        ListNodePtr current = sPtr;
        int max = sPtr->card22;
        while (current != NULL)
            {
                if (current->card22 > max)
                    {
                        max = current->card22;
                    }
                current = current->next;
            }
        printf("Max:%d \n",max);
        
    }

void findMin(ListNodePtr sPtr)
    {
        ListNodePtr current = sPtr;
        int min = sPtr->card22;
        while (current != NULL)
            {
                if (current->card22 < min)
                    {
                        min = current->card22;
                    }
                current = current->next;
            }
        printf("Min:%d \n",min);
    }


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
                    if ((current->card22 == start->card22) && (strcmp(current->surname1, start->surname1) == 0) && (strcmp(current->name1, start->name1) == 0) && (strcmp(current->patronymic1, start->patronymic1) == 0) && (strcmp(current->home1, start->home1) == 0) && (strcmp(current->telephone1, start->telephone1) == 0) && (strcmp(current->card1, start->card1) == 0))
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


 

int main(int argc, const char * argv[])
{
    ListNodePtr startPtr = NULL;
 
    int n;
    char surname[10];
    char name[10];
    char patronymic[10];
    char home[10];
    char telephone[10];
    char card[10];
    int card2 = 0;

    while(1)
    {   printf("1 Ввод данных\n");
        printf("2 Вывод данных\n");
        printf("3 Подсчет количества элементов\n");
        printf("4 Нахождение min\n");
        printf("5 Нахождение max\n");
        printf("6 Удаление повторений\n");
        printf("7 Удаление всех данных\n");
        printf("8 Выход из программы\n");
        
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
                    printf("Adress of home: ");
                    gets(home);
                    printf("Telephone: ");
                    gets(telephone);
                    printf("Numer of credit card: ");
                    gets(card);
                    printf("Numer of credit card2: ");
                    scanf("%d",&card2);
                
                insert(&startPtr, surname, name, patronymic, home, telephone, card, card2);
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
