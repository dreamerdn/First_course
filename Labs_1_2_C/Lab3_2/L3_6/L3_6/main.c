//
//  main.c
//  L3_6
#include <stdio.h>
#include <stdlib.h>


struct Spis
{
    char info;
    struct Spis* next;
};

void Create (struct Spis **begin,struct Spis **end, int s);
void Enter (struct Spis *begin);
void Del(struct Spis **begin);


int main()
{
    struct Spis *begin, *end, *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    begin=end=t;
    
    int n,size_;
        while (1)
        {   printf("Choose from these items:\n");
            printf("1)Create;");
            printf("2)Enter;");
            printf("3)End.\n");
            scanf("%d",&n);
            fflush(stdin);
    
            switch (n)
            {
                case 1:
                    printf("Max size: \n");
                    scanf("%d",&size_);
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
                    
                case 3: return 0;
                
                default: printf("Incorrect number entered.\n");
                    printf("Try again:\n");
            }
            
            
         }
    
   
    
    return 0;
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

//ввод элементов в очередь
void Create (struct Spis **begin,struct Spis **end, int s)
{   int newt;
    struct Spis *t;
    int cnt=0,n,tmp=1000;
    
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
                    fflush(stdin);
                    if(n!=1)
                    {
                        printf("%s","Invalid input. Try again.\n");
                    }
                }
                while(n!=1);
       
                if (cnt==0)
                    tmp=newt;
                
                if (cnt>=3)
                    newt=tmp;
        
            t->info=newt;
            (*end) -> next=t;
            *end=t;
                
        cnt++;
   
    }
    }
    
}

//вывод на экран введенных элементов
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



