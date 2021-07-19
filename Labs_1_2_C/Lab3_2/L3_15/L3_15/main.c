//№3_15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Spis
{
    char info;
    struct Spis* next;
};

void Create (struct Spis **begin,struct Spis **end, int s);
void Enter (struct Spis *begin);
void Enter2 (struct Spis *begin, int f);
void Del(struct Spis **begin);
void firstdel (struct Spis **begin);
void Create2 (struct Spis **begin,struct Spis **end);

int main()

{
    struct Spis *begin, *end, *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    begin=end=t;
    
    int n,size_;
        while (1)
        {   printf("Choose from these items:\n");
            printf("create - 1;\n");
            printf("enter - 2;\n");
            printf("task - 3;\n");
            printf("delete all elements - 4;\n");
            printf("end - 5;\n");
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
                    
                case 3: Create2(&begin, &end);
                    break;
                case 4: Del(&begin);
                    break;
                case 5: return 0;
                
                default: printf("Incorrect number entered.\n");
                    printf("Try again:\n");
            }
         }
    return 0;
}

//внесение в очередь элементов
void Create (struct Spis **begin,struct Spis **end, int s)
{   int newt;
    struct Spis *t;
    int cnt=0,n,frst;

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
        //проверка на вводимый элемент
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
        
        if (cnt==0)
        {
            frst=newt;
        }
        
         cnt++;
        }
    }
    printf("\n");
    firstdel (begin);
    Enter (*begin);
}

void Create2 (struct Spis **begin,struct Spis **end)
{
    int newt;
    struct Spis *t;
    int n;
    
           printf("\n");
           printf("Elemtnts:\n");
           Enter(*begin);
           
           //удаление первого элемента
           firstdel(begin);
           //вводим новый элемент
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
}

}
//вывод на экран
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
    //printf("удален - %d\n",t->info);
    *begin=(*begin)->next;
}
