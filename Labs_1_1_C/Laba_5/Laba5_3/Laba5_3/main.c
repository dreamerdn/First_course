//
//  main.c
//  Laba5_3
//
//  Created by Dasha Neyzhmak on 10/8/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//Найти в матрице первую строку, все элементы которой равны нулю. Все элементы столбца с таким же номером уменьшить вдвое.


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
               printf("%d ",arr[i][j]);
           }
            printf("\n");
       }
    
    int s,nul=0;
    for (i=0;i<n;i++){
        s=0;
        for (j=0;j<m;j++){
            s+=arr[i][j];
              }
        printf("i:%d sum:%d",i+1,s);
        if (s==0){
            nul=i;
            for (i=0;i<n;i++){
                arr[i][nul]=(arr[i][nul]/2);}
        }
        printf("\n");
        }
    
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
         printf("\n");
    }
    return 0;
}
