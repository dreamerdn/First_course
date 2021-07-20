//
//  main.c
//  Laba_3_2_c
//
//  Created by Dasha Neyzhmak on 9/22/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//
//№1
//Искомое число больше 400 и меньше 500. Составить алгоритм поиска этого числа,если сумма его цифр равна 9 и оно равняется 47/36 числа, изображенного теми же цифрами, но в обратном порядке.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m, n=9;
        
      for (m=401;m<500;m++)
       {
           int z=36*m;
           if ((m / 100 + m % 100 / 10 + m % 10 == n) &&
                (z == 47 * ((m / 100) + (m % 100 / 10) * 10 + (m % 10) * 100)))
             printf("Искомое число: %d\n",m);
           
       }
       return 0;
   }

    
   
  
