//
//  main.c
//  6_12
//
//
//  main.c
//  L6_5

#include <stdio.h>
#include <stdlib.h>

void Bubble_S(int* arr, int len);
void Bubble_S2(int* arr, int len);
void swap(int* arr, int index1, int index2);

int main(int argc, const char * argv[])
{
    
    int N=0,M=0;
    
    printf("Size of array X1:\n");
    scanf("%d",&N);
    //ввод массива
    int* X = (int*)malloc(N * sizeof(int));
    //ввод значений в массив
    //N - размер исходного массива
    for (int i=0;i<N;i++)
    {
        printf("Enter element:");
        scanf("%d",&X[i]);
    }
    
    //исходный массив
    printf("X: \n");
    for (int i=0;i<N;i++)
    {
        printf("%d ",X[i]);
    }
    printf("\n");
    
    //нахождение среднего элемента
    int tab=0, tab2=0;
    tab=N/2;
    tab2=N%2;
    //округление происходит до 0,5 включительно к меньшему
    // от 0,5 к большему числу
    if (tab2>1)
        tab=tab+1;
    
    //создаем массив для элементов СЛЕВА от среднего
    int* X2 = (int*)malloc(tab * sizeof(int));
    for (int i=0; i<tab; i++)
    {
        X2[i]=X[i];
    }
    
    printf("X2: \n");
    for (int i=0;i<tab;i++)
    {
        printf("%d ",X2[i]);
    }
    printf("\n");
    
    Bubble_S(X2,tab);
    
    printf("X2 - sorted array: \n");
       for (int i=0;i<tab;i++)
       {
           printf("%d ",X2[i]);
       }
       printf("\n");
    
    //создаем массив для элементов СПРАВА от среднего
    int tab3=0, u=0;
    tab3=N-tab;
    
    int* X3 = (int*)malloc(tab3 * sizeof(int));
    for (int i=tab; i<N; i++)
    {
        X3[u]=X[i];
        u++;
    }
    printf("X3 : \n");
    for (int i=0;i<tab3;i++)
    {
        printf("%d ",X3[i]);
    }
    printf("\n");
    Bubble_S2(X3,tab3);
    
    printf("X3 - sorted array: \n");
          for (int i=0;i<tab3;i++)
          {
              printf("%d ",X3[i]);
          }
          printf("\n");
    
    //присваиваем исходному массиву значения массива с элементами СПРАВА от среднего элемента
    for (int i=0;i<tab3;i++)
    {
        X[i]=X3[i];
    }
    
    
    int y=0;
    //присваиваем исходному массиву значения массива с элементами СЛЕВА от среднего элемента
    for (int i=tab3;i<N;i++)
    {
        X[i]=X2[y];
        y++;
    }
    
    //вывод конечного массива
    printf("X - sorted array: \n");
    for (int i=0;i<N;i++)
    {
        printf("%d ",X[i]);
    }
    printf("\n");
    
    return 0;
}



void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp;
}

//по убыванию
void Bubble_S(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

//по возростанию
void Bubble_S2(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

