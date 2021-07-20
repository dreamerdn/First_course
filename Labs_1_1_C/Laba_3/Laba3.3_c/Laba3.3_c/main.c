//
//  main.c
//  Laba3.3_c
//
//  Created by Dasha Neyzhmak on 9/16/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x1, x2, x3, x4, counter=0;
    
    for (x1=0;x1<=2;x1++) {
     
        for (x2=0;x2<=4;x2++) {
           
            for (x3=0;x3<=20;x3++) {
                
                for (x4=0;x4<=50;x4++) {
                    
                    if(100==(x1*50 + x2*20 + x3*5 + x4*2))
                    counter++;
                    
    }
        }
            }
                }
    
    printf("Number of method: %d\n",counter);
    return 0;
}
