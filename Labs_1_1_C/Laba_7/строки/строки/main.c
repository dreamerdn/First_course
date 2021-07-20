
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------
char* Creating (int n)
{
    char* a = (char*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        printf("[%d]:",i);
        scanf("%s", &a[i]);
        
        }
        
    return a;
}
//-----------------------------------
void output(char* mas, int n)
{
for (int i = 0; i < n; i++)
{
printf("%c", mas[i]);
}
    printf("\n");
}

void Enter(char* mas, int n)
{
        char sm;
        char* pointer=NULL;
        int tmp = 0;
        printf("Enter the character you are looking for: ");
        rewind(stdin);
        scanf("%c", &sm);

        pointer = strchr(mas, sm);
        for (int i=0;i<strlen(mas);i++)
        {
            if (pointer!=0)
            {
            tmp++;
            }
        }
        printf("tmp %d\n",tmp);

    }

//--------------------------------------------
int main(int argc, const char * argv[]) {
    //int n;
    int size1,size1_1;
    char *arr;
    printf("Enter size1 of array:");
    scanf("%d", &size1);
    arr = Creating(size1);
    size1_1 = size1;
    output(arr, size1);
    Enter(arr, size1);
    
    
    return 0;
}
