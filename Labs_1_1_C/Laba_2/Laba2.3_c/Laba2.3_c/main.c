//
//  main.c
//  Laba2.3_c
//
//  Created by Dasha Neyzhmak on 9/9/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int a,b,n;
    
    printf("Select math operation:\n");
    printf("1. +\n");
    printf("2. -\n");
    printf("3. *\n");
    printf("4. ÷\n");
    printf("5. =\n");
    printf("6. < or >\n");
    printf("Enter the operation number:\n");
    scanf("%d",&n);
    
    printf("Enter 2 numbers\n");
    printf("a:");
    scanf("%d",&a);
    printf("b:");
    scanf("%d",&b);
    
    
    switch(n)
    {
        case 1: printf("result= %d\n",a+b);break;
        case 2: printf("result= %d\n",a-b);break;
        case 3: printf("result= %d\n",a*b);break;
            
        case 4: if (b==0)
                    printf("Dividend cannot be 0\n");
                        else printf("result= %d\n",a/b);break;
            
        case 5: if (a==b)
                    printf("result= %d\n",a=b);
                        else  printf("a≠b\n");break;
            
        case 6: if (a>b)
                    printf("a>b\n");
                        else
                            if (a<b)
                                printf("a<b\n");
       
        default: printf("Неверный пункт оперции\n"); break;
            }
   
    
    
    return 0;
}
