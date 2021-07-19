#include <stdio.h>
#include <stdlib.h>
 
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
        printf("1) Enter elements\n");
        printf("2) Delete elements\n");
        printf("3) Delete 2 elem\n");
        printf("4)Print\n");
        printf("5) Exit\n");
        scanf("%d", &n);
 
        switch (n)
        {
 
        case 1:
                 //ввод размера стека
            printf("Max size: \n");
            scanf("%d", &size_s);
                //помещаем значения в стек
            Push(&stackPtr, size_s);
                //функция вывода, введенных элементов
            PrintS(stackPtr);
            break;
 
                //удаляем элемент с вершины стека
        case 2 :
                if (!IsEmpty(stackPtr))
            Pop(&stackPtr);
            PrintS(stackPtr);
            break;
                //выход из программы
        case 3 : //если cnt=6, то мы удаляем с вершины стека два элемента
                       for (int i=0;i<2;i++)
                       {
                       Pop(&stackPtr);
                       }
               break;
        case 4 :PrintS(stackPtr);
                 break;
                
        case 5: return 0;
 
        default: printf("Error enter :(");
            break;
        }
    }
 
    return 0;
}
 
// функция ввода элементов в стек
void Push (Stack3 *topPtr, int s)
{
    int cnt = 0, info;
    while (cnt != s)
    {
        printf("Enter an integer: ");
        scanf("%d", &info);
        Stack3 newPtr;
        //newPtr = new Stack2;
        newPtr = (Stack2*)malloc(sizeof(Stack2));
        if (newPtr != NULL)
        {
            newPtr->data = info;
            newPtr->nextPtr = *topPtr;
            *topPtr = newPtr;
            cnt++;
        }
        else
            printf("%d Error not memory \n", info);
    }
}
 
//функция удаления
int Pop(Stack3 *topPtr)
{
    Stack3 tempPtr;
    int Value;
 
    tempPtr = *topPtr;
    Value = (*topPtr)->data;
    printf("deleted character: %d\n", Value);
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return Value;
}
 
 
//функция вывода на консоль элементов стека
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
