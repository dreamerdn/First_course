//
//  main.c
//  L6_6


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
    //ввод значений в массив
    //n - размер исходного массива
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
            l++;
        
    }
    
    int Cnt_ = n-l;
     
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
