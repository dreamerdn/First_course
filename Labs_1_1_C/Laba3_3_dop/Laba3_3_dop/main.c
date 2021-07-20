#include <stdio.h>
#include <string.h>

//найти слово с наибольшей длиной

int main () {
    
char str[1024];

    printf ("Введите строку\n");
    gets (str);
    int len=strlen(str);
    int max=0, i_max=0, cnt=0;
    
    for (int i=0; i<len; i++)
    {
        if (str[i]!=' ')
            cnt++;
        else
            cnt=0;
        if (cnt > max)
        {
            max=cnt;
            i_max=i-cnt+1;
        }
    
    }
    
       int cnt2=max+i_max;
    printf("longest word is: ");
    for (int i=i_max;i<cnt2;i++)
    {
        printf("%c",str[i]);
       
    }
     printf("\n");
return 0;
    
}
 
 


