//
//  main.c
//  L6_5

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int len);
void bubbleSort2(int* arr, int len);
void swap(int* arr, int index1, int index2);

int main(int argc, const char * argv[])
{
    
    int N=0,M=0;
    
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
    bubbleSort2(A,N);
    printf("A: \n");
    for (int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    
    printf("Size of array X2:\n");
    scanf("%d",&M);
    int* B = (int*)malloc(M * sizeof(int));
    for (int i=0;i<M;i++)
    {
      printf("Enter element:");
      scanf("%d",&B[i]);
    }
    bubbleSort(B,M);
    printf("B: \n");
    for (int i=0;i<M;i++)
    {
        printf("%d ",B[i]);
    }
    printf("\n");
    
    
    
    
    int cnt=M+N;
    int* C = (int*)malloc(cnt * sizeof(int));
    for (int i=0;i<N;i++)
    {
        C[i] = A[i];
    }
    
    int j=0;
    for (int i=N;i<cnt;i++)
    {
     C[i] = B[j];
        j++;
    }
    
    bubbleSort2(C,cnt);
    printf("\nC: \n");
    for (int q=0;q<cnt;q++)
    {
        printf("%d ",C[q]);
    }
    printf("\n");
}



void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
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
