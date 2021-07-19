//
//  main.c
//  L6_7_c

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int len);
void bubbleSort2(int* arr, int len);
void swap(int* arr, int index1, int index2);

int main(int argc, const char * argv[])
{
    
    int N=0,M=0;
    //СОЗДАЕМ ПЕРВЫЙ МАССИВ А
    printf("Size of array X1:\n");
    scanf("%d",&N);
    //ввод массива
    int* A = (int*)malloc(N * sizeof(int));
    //ввод значений в массив
    //N - размер исходного массива
    for (int i=0;i<N;i++)
    {
        printf("Enter element:");
        scanf("%d",&A[i]);
    }
    //сортировка пузырьком
    bubbleSort2(A,N);
    //выводит отсортированный массив
    printf("A: \n");
    for (int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    //СОЗДАЕМ ПЕРВЫЙ МАССИВ В
    printf("Size of array X2:\n");
    scanf("%d",&M);
    int* B = (int*)malloc(M * sizeof(int));
    for (int i=0;i<M;i++)
    {
      printf("Enter element:");
      scanf("%d",&B[i]);
    }
    bubbleSort2(B,M);
    printf("B: \n");
    for (int i=0;i<M;i++)
    {
        printf("%d ",B[i]);
    }
    printf("\n");
    
    
    
    int tmp=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
        if (A[i]>B[j])
        {
            tmp=B[j];
            B[j]=A[i];
            A[i]=tmp;
        }
            
        }
    }
    printf("\n");
    
    printf("Sorted all:\n");
    bubbleSort2(A,N);
    for (int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    bubbleSort2(B,M);
    for (int i=0;i<M;i++)
    {
        printf("%d ",B[i]);
    }
    printf("\n");
    
    return 0;
}



void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp;
}


void bubbleSort2(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}
