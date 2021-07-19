//
//  main.c
//  L6_8
 
#include <stdio.h>
#include <stdlib.h>
 
void bubbleSort(int* arr, int len);
void bubbleSort2(int* arr, int len);
void swap(int* arr, int index1, int index2);
 
int main(int argc, const char * argv[])
{
 
    int n,cnt=0,cnt2=0,cnt3=0;
    printf("Size of array:\n");
    scanf("%d",&n);
    //ввод массива
    int* X = (int*)malloc(n * sizeof(int));
 
    for (int i=0;i<n;i++)
    {
        printf("Enter element:");
        scanf("%d",&X[i]);
    }
 
    //вывод ВСЕГО массива
    printf("All array\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\n",X[i]);
    }
    printf("\n");
 
    //отрицательные элементы
    for (int i=0;i<n;i++)
    {
       if (X[i]<0)
        cnt++;
    //положительные элементы
       else if (X[i]>0)
        cnt2++;
       else if (X[i]==0)
        cnt3++;
    }
 
    
    
    int* A = (int*)malloc(cnt * sizeof(int));
    int* B = (int*)malloc(cnt2 * sizeof(int));
    int* C = (int*)malloc(cnt3 * sizeof(int));
    int j=0, k=0, l=0;
    
    for (int i=0;i<n;i++)
    {
        if (X[i]<0)
        {
            A[j] = X[i];
            j++;
        }
 
        if (X[i]>0)
        {
            B[k] = X[i];
            k++;
        }
        
        if (X[i]==0)
        {
            C[l] = X[i];
            l++;
        }
 
    }
 
    //сортировка отрицательных элементов
    bubbleSort(A,cnt);
    bubbleSort2(B,cnt2);
 
    //вывод отрицательных элементов
    printf("Negative elements\n");
    for (int i=0;i<cnt;i++)
       {
           printf("%d\n",A[i]);
       }
    //вывод положительных элементов
    printf("Positive elements\n");
    for (int i=0;i<cnt2;i++)
       {
           printf("%d\n",B[i]);
       }
 
    int* Z = (int*)malloc(n * sizeof(int));
    int q=0;
    for (int i=0;i<cnt;i++)
    {
        Z[i]=A[i];
        q++;
    }
 
    for (int i=0;i<cnt2;i++)
    {
        Z[q]=B[i];
        q++;
    }
 
    for (int i=q;i<k;i++)
    {
        for (int j=0;j<l;j++)
        {
            Z[i]=C[j];
        }
        
    }
 
 
 
    printf("sorted All array\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\n",Z[i]);
    }
 
    return 0;
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
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}
 
void bubbleSort2(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}
