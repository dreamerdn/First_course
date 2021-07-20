//
//  main.c
//  Laba5_2
//
//  Created by Dasha Neyzhmak on 10/8/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//Дана целочисленная квадратная матрица.
//Определить произведение элементов в тех строках, которые не содержат отрицательных элементов;
//максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.


#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    //размер массива
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    
    //рандомное заполнение массива
    int i,j=0,arr[n][n];
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                printf("arr[%d][%d]: ",i,j);
                scanf("%d",&arr[i][j]);
                //tmp=(rand() % (-10));
              //  arr[i][j]=tmp;
            }
            
        }
    //вывод массива
    printf("Array: \n");
    for (i=0;i<n;i++){
               for (j=0;j<n;j++){
    printf("%d ",arr[i][j]);
               }
        printf("\n");
    }
    
    //найти произведение в строке, где нет отрицательных элементов массива
    int p;
    for (i=0;i<n;i++){
        p=1;
        for (j=0;j<n;j++){
            if (arr[i][j]>0)
                p*=arr[i][j];
            if (arr[i][j]<0)
                p/=arr[i][j];
               }
        if (p>0)
        printf("string %d p= %d\n",i+1,p);
    }
    
    //максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы
    int sum_1=0,sum_2=0,max=0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (j==i+1)
                sum_1+=arr[i][j];
            if (i==j+1)
                 sum_2+=arr[i][j];
            }
        if (sum_1<sum_2)
            max=sum_2;
        else max=sum_1;
    }
        printf("max sum: %d\n",max);
    
    return 0;
}
