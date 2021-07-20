//
//  main.c
//  function_substr
//
//  Created by Dasha Neyzhmak on 10/29/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//ПОЛНАЯ ХУЕТА

#include <stdio.h>
int substr (char *s1,char *s2)
{
    int t;
    char *p, *p2;
//ПОЛНАЯ ХУЕТА
    for (t=0; s1[t]; t++)
    {
        p=&s1[t];// t - символ подстроки
        p2=s2;// строка
 //ПОЛНАЯ ХУЕТА
        while (*p2 && (*p2==*p) )
        {p++;
            p2++;
        }
//ПОЛНАЯ ХУЕТА
        if (!*p2)
        { printf("подстрока найдена\n");
            return t;
        }
        else
        printf("подстрока не найдена\n");
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
         char stroka[1024];
         printf ("Enter string: \n");
         gets (stroka);
         gets (stroka);
         char symbol[10];
           
                printf("Enter the character you are looking for: ");
                rewind(stdin);
                gets (symbol);
        substr(symbol,stroka);
    
    return 0;
}
