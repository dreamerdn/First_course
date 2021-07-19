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

void Push (Stack3 *topPtr, int s);
int Pop(Stack3 *topPtr);
void PrintS(Stack3 currentPtr);
int IsEmpty(Stack3 topPtr);


int main(int argc, const char* argv[])
{
    Stack3 stackPtr = NULL;
    int n, size_s;
 
 
    while (1)
    {
        printf("Choose point: \n");
        printf("1. Introduce stack elements.\n");
        printf("2. Delete stack elements.\n");
        printf("3. Exit.\n");
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

//функция ВВОДА элементов в стек
void Push (Stack3 *topPtr, int s)
{
    int cnt = 0, info, frst=900;
    //S - количесво элементов в стеке
    //пока cnt < s выполняется ввод символов
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
            
            //помещаем значение первого введенного эоемента в переменную frst
            if (cnt==0)
            {
                frst=info;
            }
            //вывод размера введенного стека
            if (info==frst && cnt!=0)
            {
                printf("Injected stack SIZE: %d\n",cnt+1);
            }
            cnt++;
        }
        else
            printf("%d Error not memori \n", info);
        
    }
}

//функция УДАЛЕНИЯ элемента из стека
//удаляется элемент, последний вошедший в стек
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

//функция ВЫВОДА значений стека
void PrintS(Stack3 currentPtr)
{
    if (currentPtr == NULL)
        printf("Error not stack\n");
    else
    {
        printf("\nStack is: \n");
        while (currentPtr != NULL)
        {
            printf("%d ->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n");
    }
}

//проверка на пустой стек
int IsEmpty(Stack3 topPtr)
{
    return topPtr == NULL;
}
 
