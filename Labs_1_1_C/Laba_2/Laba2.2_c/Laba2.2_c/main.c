//
//  main.c
//  Laba2.2_c
//
//  Created by Dasha Neyzhmak on 9/8/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    float a,b,h;
    int r;
    r=1;
        printf("Enter point coordinates:\n");
        scanf("%f%f",&a,&b);
    h = sqrt(a*a+b*b);
   // printf("h: %f\n",h);
    if ((h<r)&&(b>0))
        printf("Do belong to the top of the circle.\n");
    else
        printf("The point NOT belongs to the top of the circle.\n");
    
    return 0;
}
 
