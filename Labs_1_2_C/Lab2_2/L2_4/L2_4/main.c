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
 
//функция ввода элементов в стек
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
            if (cnt%2==0)
            info=info*(-1);
        
                newPtr->data = info;
                newPtr->nextPtr = *topPtr;
                *topPtr = newPtr;
            
            
            cnt++;
                
        }
        else
            printf("%d Error not memori \n", info);
    }
}
 
//функция удаления жлементов из стека
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

//вывод содержимого стека на экран
void PrintS(Stack3 currentPtr)
{
    if (currentPtr == NULL)
        printf("Error not stack\n");
    else
    {
        printf("Stack is: \n");
        while (currentPtr != NULL)
        {
            printf(", %d", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n");
    }
}
 
int IsEmpty(Stack3 topPtr)
{
    return topPtr == NULL;
}
 


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
 
        switch (n)
        {
        case 1:
            printf("Max size: \n");
            scanf("%d", &size_s);
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

