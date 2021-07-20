//
//  main.c
//  cортировка побочной диагонали
//
//  Created by Dasha Neyzhmak on 10/15/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    int tmp;
    for (i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (arr[j][n-1-j] > arr[i][n-1-i]){
                tmp = arr[j][n-1-j];
                arr[j][n-1-j] = arr[i][n-1-i];
                arr[i][n-1-i] = tmp;
           }
        }
    }
    return 0;
}
