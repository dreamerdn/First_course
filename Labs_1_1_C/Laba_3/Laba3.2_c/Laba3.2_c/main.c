//
//  main.c
//  Laba3.2_c
//
//  Created by Dasha Neyzhmak on 9/16/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float a,b,h,x,Fx;

    printf("Enter [a,b]\n");
    printf("a: \n");
    scanf("%f",&a);
    printf("b: \n");
    scanf("%f",&b);
    printf("Enter h\n");
    scanf("%f",&h);
    x=a;
    do
    {
    Fx=((x+1)*(x-2)*(2*x-3));
    printf("%f\n",Fx);
        x+=h;
    }
    while (x<=b);
   
    return 0;
}
