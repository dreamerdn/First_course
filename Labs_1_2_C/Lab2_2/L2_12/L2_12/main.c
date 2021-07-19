// L2_12
#include <stdio.h>
#include <stdlib.h>

//стек1
struct Stack_1
{
    char  data;
    struct Stack_1* nextPtr;
};

//typedef тип имя;
//Где тип — это любой существующий тип данных,а имя - это новое имя для данного типа.
//Новое имя определяется в дополнение к существующему имени типа, а не замещает его
typedef struct Stack_1 StackOne;
typedef StackOne * StackOnePtr;
 
//стек2
struct Stack_2
{
    char  data;
    struct Stack_2* nextPtr2;
};

typedef struct Stack_2 StackSec;
typedef StackSec * StackSecPtr;

//прототипы функций
void Push (StackOnePtr *topPtr,StackSecPtr *topPtr2, int s1, int s2);
int Pop(StackOnePtr *topPtr);
int Pop2(StackSecPtr *topPtr);
void PrintS(StackOnePtr currentPtr);
void PrintS2(StackSecPtr currentPtr2);
int IsEmpty(StackOnePtr topPtr);
int Acheсk (int n);


int main(int argc, const char* argv[])
{
    StackOnePtr  stackPtr = NULL;
    StackSecPtr  stackPtr2 = NULL;
    int n, size_1, size_2;
 
 
    while (1)
    {
        printf("Choose point: \n");
        printf("1. Enter\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        scanf("%d", &n);
 
        switch (n)
        {
                //установка размера стеков
                //заполнение стеков
                //вывод результата
        case 1:
            printf("Max size of first stack: \n");
            scanf("%d", &size_1);
                //printf("Max size of second stack: \n");
                //scanf("%d", &size_2);
                size_2=size_1;
            Push(&stackPtr, &stackPtr2, size_1, size_2);
            PrintS(stackPtr);
            PrintS2(stackPtr2);
            break;
                //удаление элементов стека
        case 2 :
                if (!IsEmpty(stackPtr))
                    printf("The popped value is %d and %d\n", Pop(&stackPtr),Pop2(&stackPtr2));
            PrintS(stackPtr);
                PrintS2(stackPtr2);
            break;
                // выход из программы
        case 3: return 0;
 
        default: printf("Error enter :(");
            break;
        }
    }
 
    return 0;
}

//функция ввода элементов в стек
void Push (StackOnePtr *topPtr, StackSecPtr *topPtr2, int s1, int s2)
{
    int cnt = 0, cnt2=0;
    char info;

    while (cnt != s1)
    {
         
        printf("Enter an element: ");
        //scanf("%c", &info);
        //scanf("%c", &info);
        gets(&info);
         gets(&info);
        StackOnePtr newPtr;
        newPtr = (StackOne*)malloc(sizeof(StackOne));
        if (newPtr != NULL)
        {
            newPtr->data = info;
            newPtr->nextPtr = *topPtr;
            *topPtr = newPtr;
            cnt++;
        }
        
            StackSecPtr newPtr2;
            newPtr2 = (StackSec*)malloc(sizeof(StackSec));
            if (newPtr2 != NULL)
            {
                info=info;
                newPtr2->data = info;
                newPtr2->nextPtr2 = *topPtr2;
                *topPtr2 = newPtr2;
                cnt2++;
            }
    }
    
}
 
//функция удаления #1
int Pop(StackOnePtr *topPtr)
{
    StackOnePtr tempPtr;
    int Value;
 
    tempPtr = *topPtr;
    Value = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return Value;
}

//функция удаления #2
int Pop2(StackSecPtr *topPtr)
{
    StackSecPtr tempPtr;
    int Value;
 
    tempPtr = *topPtr;
    Value = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr2;
    free(tempPtr);
    return Value;
}


//вывод первого стека на экран
void PrintS(StackOnePtr currentPtr)
{
    if (currentPtr == NULL)
        printf("Error not stack\n");
    else
    {
        printf("Stack #1 is: \n");
        while (currentPtr != NULL)
        {
            printf("%c ->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n");
    }
}

//вывод второго стека на экран
void PrintS2 (StackSecPtr currentPtr2)
{
    if (currentPtr2 == NULL)
        printf("Error not stack\n");
    else
    {
        printf("Stack #2 is: \n");
        while (currentPtr2 != NULL)
        {
            printf("%c ->", currentPtr2->data);
            currentPtr2 = currentPtr2->nextPtr2;
        }
        printf("\n");
    }
}
 
int IsEmpty(StackOnePtr topPtr)
{
    return topPtr == NULL;
}
 

/*int Acheсk (int n)
{
    int a;
    do
    {
        n=scanf("%d",&a);
        fflush(stdin);
        if(n == 1)
        {
            printf("%s","Invalid input. Try again.\n");
        }
    }
    while(n!=1);
    
    return n;
}
*/
