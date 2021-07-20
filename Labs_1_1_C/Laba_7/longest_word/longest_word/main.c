#include <stdio.h>
#include <string.h>

//найти слово с наибольшей длиной

int main () {
    
char str[1024];
char str2[1024];
int max=0, i_max=0, cnt=0,w=0;
    
    printf ("Введите строку\n");
    gets (str);
    int len=strlen(str);
    //int len2=strlen(str2);
    
    int tmp=9;
    int tmp2=9999;
    
    for (int i=0; i<len; i++)
    {
        if (str[i]!=' ')
        {
            if (cnt==0)
                tmp2=i;
            cnt++;
        }
        else
            if ((cnt%2)==0)
            {
                //tmp=cnt%2;
                for (int i=tmp2; i<cnt+tmp2; i++)
                {
                   str2[w]=str[i];
                    w++;
                }
                
            }
        
            if (str[i]==' ')
                cnt=0;
        }
    
    
    
   // int cnt2=max+i_max;
    printf("longest word is: ");
    for (int i=0;i<w;i++)
    {
        printf("%c",str2[i]);
       
    }
     printf("\n");
return 0;
    
}
 
 

