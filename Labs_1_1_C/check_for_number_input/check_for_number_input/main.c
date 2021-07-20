#include<stdio.h>

void Acheсk ();
FILE* f1;
int n1[3];
int a,n;

int main(void)
{
    if (!(f1 = fopen("NameA2.txt", "w+t")))
     {
         printf("Cant make a file\n");
         return 0;
     }
     printf("NameA\n");
     for (int i = 0; i < 3; i++)
     {
         printf("Vvedite stroky nomer %d\n", i+1);
         Acheсk ();
         n1[i]=a;
         fprintf(f1, "%d\n", n1[i]);
     }
    for (int i=0; i<3; i++)
    {
        fscanf(f1, "%d", &n1[i]);
        printf("NameA2: %d\n", n1[i]);
    }
   fclose(f1);
return 0;
}


void Acheсk ()
{
    do
    {
    n=scanf("%d",&a);
    fflush(stdin);
        if(n==1)
        {
        printf("%s","Good!\n");
        }
    else
        printf("%s","Invalid input. Try again.\n");
    }
    while(n!=1);
    
}
