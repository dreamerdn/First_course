//
//  main.c
//  Laba_6_1
//
//  Created by Dasha Neyzhmak on 10/15/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
// В одномерном массиве, состоящем из к целых элементов, вычислить: - количество положительных элементов массива; - сумму элементов массива, расположенных после последнего элемента, равного нулю.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
 //выделение динамическрй памяти для одномерного массива
 int size;
 int flag=0;
 printf("Enter size:");
 scanf("%d", &size);
    
     float* arr = (float*)malloc(size*sizeof(float));
    
//вводим элементы массива
    for (int i=0;i<size;i++){
        printf("Enter arr[%d]: ",i);
        scanf("%f",&*(arr+i));
        if (*(arr+i)==0)
            flag=1;
    }
    
    
    int cnt=0;
    //- количество положительных элементов массива;
    for (int i=0;i<size;i++){
        if (*(arr+i)>0)
            cnt++;
    }
    printf("positive numbers: %d\n",cnt);
    
    if (flag!=1)
    {
        printf("no nul\n");
        return 0;
    }
    
    //- сумму элементов массива, расположенных после последнего элемента, равного нулю.
    int nul=0,sum=0;
    
    for (int i=0;i<size;i++){
        if (*(arr+i)==0)
            nul=i;
        }
    
    for (int i=0;i<size;i++){
    if (i > nul)
    sum += *(arr+i);
    }
    
    printf("sum= %d\n",sum);
    
    free (arr);

    return 0;
}
