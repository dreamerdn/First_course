//
//  main.c
//  Laba5_1
//
//  Created by Dasha Neyzhmak on 10/6/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//Дана матрица вещественных чисел N х М. Количество строк N и столбцов М задается пользователем. Найти максимальный и минимальный элемент в каждой строке и поменять их местами. Найти сумму элементов на главной диагонали.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,m;
    printf("Введите количество элементов массива n и m: ");
    scanf("%d%d",&n,&m);
     
    int i,j,arr[n][m];
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("arr[%d][%d]: ",i,j);
             scanf("%d", &arr[i][j]);
        }
        
    }
    
    for (i=0;i<n;i++){
       for (j=0;j<m;j++){
        printf("%d ", arr[i][j]);
    }
        printf("\n");
    }
    
    
    
    //поиск максимального и минимального
    int max,min,j_max=0,j_min=0,cnt=0;
     int tmp;
        for(i=0;i<n;i++){
            max=arr[i][0];
               min=arr[i][0];
            for (j=0;j<m;j++){
            if (max<arr[i][j]){
                max=arr[i][j];
                j_max=j;
              
            }
            if (min>arr[i][j]){
                min=arr[i][j];
                j_min=j;
                cnt++;
            }
            }
            tmp=arr[i][j_max];
            arr[i][j_max]=arr[i][j_min];
            arr[i][j_min]=tmp;
            
            printf("Строка №%d: max: %d j=%d\n",i+1,max,j_max);
            printf("Строка №%d: min: %d j=%d\n",i+1,min,j_min);
            printf("\n");
    }
    
    
    //меняем местами максимальный и минимальный элементы СТРОКИ!!!!!!!
   printf("Вывод массива, наибольший и наименьший элемент в строке поменялись местами:\n");
    for (i=0;i<n;i++){
       for (j=0;j<m;j++){
        printf("%d ", arr[i][j]);
    }
        printf("\n");
    }
    
    //сумма элементов на главной диагонали
    int sum=0;
    for (i=0;i<n;i++){
        sum+=arr[i][i];
        }
    printf("sum= %d\n",sum);
    return 0;
}
