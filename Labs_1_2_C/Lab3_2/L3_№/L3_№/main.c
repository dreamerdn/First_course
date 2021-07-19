
//№3


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Spis
{
    char info;
    struct Spis* next;
};


//функция ввода элементов в очередь
void Create (struct Spis **begin,struct Spis **end, int s, int r)
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
        fflush(stdin);
            if(n!=1)
            {
            printf("%s","Invalid input. Try again.\n");
            }
        }
        while(n!=1);
       
            t->info=newt;
            (*end) -> next=t;
            *end=t;
        
        //когда эталонный элемент будет равен введенному элементу, количество элементов очереди выведется на экран
        if (r==newt)
        {
            printf("Stack size: %d\n", cnt+1);
            //увеличиваем прохождение по данному циклу до s-1
            cnt=s-1;
        }
        // увеличиваем до s и завершаем ввод элементов в очередь
        cnt++;
       
    }
    }
    
}

//функция вывода
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




int main()
{
    struct Spis *begin, *end, *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    begin=end=t;
    
    int n,size_,ref,n2;
        while (1)
        {   printf("Choose from these items:\n");
            printf("create 1; enter 2; end 3\n");
            scanf("%d",&n);
            fflush(stdin);
    
            switch (n)
            {
                case 1:
                    //ввод размера очереди
                    printf("Max size: \n");
                    //проверка на ввод
                    do
                    {
                    n=scanf("%d",&size_);
                    fflush(stdin);
                        if(n!=1)
                        {
                        printf("%s","Invalid input. Try again.\n");
                        }
                    }
                    while(n!=1);
                    //ввод эталонного элемента
                    printf("Reference element: \n");
                    do
                    {
                    n2=scanf("%d",&ref);
                    fflush(stdin);
                        if(n2!=1)
                        {
                        printf("%s","Invalid input. Try again.\n");
                        }
                    }
                    while(n2!=1);
                    Create(&begin, &end, size_,ref);
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

