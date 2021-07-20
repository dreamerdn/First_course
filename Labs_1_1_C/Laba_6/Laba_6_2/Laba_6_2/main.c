//
//  main.c
//  Laba_6_2
//
//  Created by Dasha Neyzhmak on 10/15/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//  Дана целочисленная квадратная матрица.
//  Определить произведение элементов в тех строках, которые не содержат отрицательных элементов;
//  Максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.


#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    //выделение динамическрй памяти для двумерного массива
    int size;
    printf("size: ");
    scanf("%d", &size);
        int** arr = (int**)malloc(size*sizeof(int));
            for (int i=0; i<size; i++)
            {
                arr[i]=(int*)malloc(size*sizeof(int));
            }

        for (int i=0;i<size;i++){
            for (int j=0;j<size;j++){
                printf("arr[%d][%d]: ",i,j);
                scanf("%d",&*(*(arr + i)+j)); //*(*(arr + i)+j)
            }
            
        }
    //вывод массива
    printf("Array: \n");
    for (int i=0;i<size;i++){
               for (int j=0;j<size;j++){
    printf("%d ",*(*(arr + i)+j));
               }
        printf("\n");
    }
    
    //найти произведение в строке, где нет отрицательных элементов массива
    int p;
    for (int i=0;i<size;i++){
        p=1;
        for (int j=0;j<size;j++){
            if (*(*(arr + i)+j)>0)
                p*=*(*(arr + i)+j);
            if (*(*(arr + i)+j)<0)
                p/=*(*(arr + i)+j);
               }
        if (p>0)
        printf("string %d p= %d\n",i+1,p);
    }
    
    //максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы
    int sum_1=0,sum_2=0,max=0;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if (j==i+1)
                sum_1+=*(*(arr + i)+j);
            if (i==j+1)
                 sum_2+=*(*(arr + i)+j);
            }
        if (sum_1<sum_2)
            max=sum_2;
        else max=sum_1;
    }
        printf("max sum: %d\n",max);
    
    free (arr);
    return 0;
}
