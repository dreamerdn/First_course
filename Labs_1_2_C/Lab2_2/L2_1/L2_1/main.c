//
//  main.c
//  L2_21
//
//  Created by Dasha Neyzhmak on 2/25/21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.

//+1 ввод максимального размера стека с экрана
//+2 ф-ция ввода
//+3 ф-ция вывода
//+4 удаление элемента из стека

#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>
//# include <string.h>

//стек
struct Stack_s
{
    int  data;
    struct Stack_s* nextPtr;
};
 
typedef struct Stack_s Stack2;
typedef Stack2 * Stack3;
 
//прототипы функций
void Push (Stack3 *topPtr, int s);
int Pop(Stack3 *topPtr);
int IsEmpty(Stack3 topPtr);
void PrintS(Stack3 currentPtr);

 
int main(int argc, const char* argv[])
{
    Stack3 stackPtr = NULL;
    int n, size_s;
 
 
    while (1)
    {
        printf("Choose point: \n");
        printf("1. Enter\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        scanf("%d", &n);
        //проверка на ввод
        fflush(stdin);
        switch (n)
        {
        case 1:
            printf("Max size: \n");
            scanf("%d", &size_s);
            fflush(stdin);
            Push(&stackPtr, size_s);
            PrintS(stackPtr);
            break;
 
        case 2 :
                if (!IsEmpty(stackPtr))
                    printf("The popped value is %d\n", Pop(&stackPtr));
            PrintS(stackPtr);
            break;
        case 3: return 0;
 
        default: printf("Error enter :(");
            break;
        }
    }
 
    return 0;
}


void Push (Stack3 *topPtr, int s)
{
    int cnt = 0, info;
    while (cnt != s)
    {
        printf("Enter an integer: ");
        scanf("%d", &info);
        fflush(stdin);
        Stack3 newPtr;
        newPtr = (Stack2*)malloc(sizeof(Stack2));
        if (newPtr != NULL)
        {
            newPtr->data = info;
            newPtr->nextPtr = *topPtr;
            *topPtr = newPtr;
            cnt++;
            if (cnt == 5)
            {
                Stack3 tempPtr;
                int Value;
 
                tempPtr = *topPtr;
                Value = (*topPtr)->data;
                *topPtr = (*topPtr)->nextPtr;
                free(tempPtr);
            }
        }
        else
            printf("%d Error not memori \n", info);
    }
}
 
int Pop(Stack3 *topPtr)
{
    Stack3 tempPtr;
    int Value;
 
    tempPtr = *topPtr;
    Value = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return Value;
}
 
void PrintS(Stack3 currentPtr)
{
    if (currentPtr == NULL)
        printf("Error not stack\n");
    else
    {
        printf("Stack is: \n");
        while (currentPtr != NULL)
        {
            printf("%d ->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n");
    }
}
 
int IsEmpty(Stack3 topPtr)
{
    return topPtr == NULL;
}
