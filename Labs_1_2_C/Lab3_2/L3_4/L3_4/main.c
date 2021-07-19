//
//  main.c
//  L3_4


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Spis
{
    char info;
    struct Spis* next;
};

void Enter (struct Spis *begin)
{
    struct Spis *t=begin;
    if (t==NULL)
    {
        printf("Spis is empty :(\n");
    }
        else
        {
            while (t!=NULL)
            {
                printf("%d \n", t->info);
                t=t->next;
            }
        }
}

//запись элементов в очередь
void Create (struct Spis **begin,struct Spis **end, int s)
{   int newt;
    struct Spis *t;
    int cnt=0,n;
    
    while (cnt!=s)
    {
    t = (struct Spis*)malloc(sizeof(struct Spis));
    t->next =NULL;
    
    if (*begin==NULL)
    {
        *begin=*end=t;
    }
    else
    {
        printf("Enter new element: \n");
        do
        {
        n=scanf("%d",&newt);
            //проверка на вводимый элемент
        fflush(stdin);
            if(n!=1)
            {
            printf("%s","Invalid input. Try again.\n");
            }
        }
        while(n!=1);
       
       
        
        if (newt>0)
        {
            t->info=newt;
            (*end) -> next=t;
            *end=t;
        }
        
         //если вводимый элемент <0, то увеличиваем счетчик до максимального значения - 1, а потом до максимального
        else if (newt<0)
        {
                t->info=newt;
                (*end) -> next=t;
                *end=t;
            
            cnt++;
            printf("Queue size: %d\n",cnt);
            printf("\n");
            //до максимального значения - 1
            cnt=s-1;
        }
        //а потом до максимального
        cnt++;
    }
    }
    printf("\n");
    Enter (*begin);
    
}


void Acheсk ()
{
    int n,a;
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

//удаление всех элементов
void Del(struct Spis **begin)
{
    struct Spis *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    while (*begin!=NULL)
    {
        t=*begin;
        *begin=(*begin)->next;
        free (t);
    }
}

//удаление первого
void firstdel (struct Spis **begin)
{
    struct Spis *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    t=*begin;
    *begin=(*begin)->next;
}

int main()
{
    struct Spis *begin, *end, *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    begin=end=t;
    
    int n,size_;
        while (1)
        {   printf("Choose from these items:\n");
            printf("1 - create;\n");
            printf("2 - show enter elements;\n");
            printf("3 - delete all;\n");
            printf("4 - end;\n");
            scanf("%d",&n);
            fflush(stdin);
    
            switch (n)
            {
                case 1:
                    printf("Max size: \n");
                    scanf("%d", &size_);
                    Create(&begin, &end, size_);
                    break;
                    
                case 2:
                   printf("Elemtnts:\n");
                   if (begin==NULL)
                   {
                       printf("no elements\n");
                   }
                   else
                   {
                       Enter(begin);
                   }
                    break;
                    
                case 3:Del(&begin);
                    break;
                
                case 4: return 0;
                default: printf("Incorrect number entered.\n");
                    printf("Try again:\n");
            }
            
            
         }
    
   
    
    return 0;
}
