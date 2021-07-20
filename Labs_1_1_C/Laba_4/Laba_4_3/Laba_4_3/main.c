//
//  main.c
//  Laba_4_3
//
//  Created by Dasha Neyzhmak on 10/4/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.

//Даны массивы A из n элементов и B из m элементов. Содержится ли наибольший элемент массива A в массиве B?


#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int A[n],tmp;
    for (i=0;i<n;i++){
        tmp=(rand() % 20);
        A[i]=tmp;
        printf("A[%d]: %d\n",i,A[i]);
    }
    
    printf("\n");
    
    int m;
    printf("Enter m: ");
    scanf("%d",&m);
    int B[m];
    for (i=0;i<m;i++){
        tmp=(rand() % 20);
        B[i]=tmp;
        printf("B[%d]: %d\n",i,B[i]);
    }
    
    int maxA;
    maxA=A[0];
    for (i=0;i<n;i++){
        if (A[i]>maxA)
            maxA=A[i];
    }
    int maxB;
    maxB=B[0];
    for (i=0;i<n;i++){
        if (B[i]>maxB)
            maxB=B[i];
    }
    
    if (maxA==maxB)
        printf("maxA=maxB=%d\n",maxA);
    else printf("The largest values of the arrays are not equal.\n");
    return 0;
}
