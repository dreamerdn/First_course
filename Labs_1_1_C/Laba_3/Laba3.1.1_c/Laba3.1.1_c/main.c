//
//  main.c
//  Laba3.1.1_c
//
//  Created by Dasha Neyzhmak on 9/16/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    
    int weight = 3000,ny, nx, i, x, y; //x=130,y=160
    nx = 0;
    for (i = 160; i <= weight; i += 160)
    {
    x = (weight - i);
    nx++; //столько раз вместятся 160кг
    if (x % 130 == 0)
    break;
    }
    printf("nx= %d\n", nx);
   
    ny = 0;
    for (i = 130; i <= weight; i += 130)
    {
    y = (weight - i);
    ny++; //столько раз вместятся 130 кг
    if (y % 160 == 0)
    break;
    }
    printf("ny= %d\n", ny);

    
    return 0;
    
}
