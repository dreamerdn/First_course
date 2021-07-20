//
//  main.c
//  Laba4_2
//
//  Created by Dasha Neyzhmak on 10/4/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//
//В одномерном массиве, состоящем из к целых элементов, вычислить: - количество положительных элементов массива; - сумму элементов массива, расположенных после последнего элемента, равного нулю.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    
    int arr[n],i;
    for (i=0;i<n;i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    
    int cnt=0;
    // количество положительных элементов массива;
    for (i=0;i<n;i++){
        if (arr[i]>0)
            cnt++;
    }
    printf("cnt: %d\n",cnt);
    
    // сумму элементов массива, расположенных после последнего элемента, равного нулю.
    
    int nul=0,sum=0;
    for (i=0;i<n;i++)
        {
            if (arr[i]==0)
            nul=i;
           // else printf("no nul\n");
            
        }
    
    for (i = 0; i < n; i++) {
        if (i > nul)
            sum += arr[i];
    }
    
    printf("sum= %d\n",sum);
    
    return 0;
}
