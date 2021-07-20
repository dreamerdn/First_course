//
//  main.c
//  Laba2.1_c
//
//  Created by Dasha Neyzhmak on 9/8/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int x1,y1,x2,y2,x3,y3,Xa,Ya,Xb,Yb;
    printf("Enter the dimensions of the sides of the triangle: \n");
    printf("Enter the coordinates of the FIRST point:\n");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinates of the SECOND point:\n");
    scanf("%d%d",&x2,&y2);
    printf("Enter the coordinates of the THIRD point:\n");
    scanf("%d%d",&x3,&y3);
    
    Xa = x2-x1;
    Ya = y2-y1;
    Xb = x2-x3;
    Yb = y2-y3;
   
    
    if ((Xa*Xb+Ya*Yb)==0)
        printf("Triangle rectangular\n");
    else if ((Xa*Xb+Ya*Yb)<0)
        printf("Triangle obtuse\n");
    else if ((Xa*Xb+Ya*Yb)>0)
    printf("Triangle acute-angled\n");
    
    return 0;
}
