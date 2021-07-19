//
//  main.c
//  L3
//
//  Created by Dasha Neyzhmak on 3/2/21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.
//
//+1 макс размер с экрана
//+2 ввод
//+3 вывод
//+4 если последний и первый одинаковые заменить на первый

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Spis
{
    char info;
    struct Spis* next;
};

void Create (struct Spis **begin,struct Spis **end, int s)
{   int newt;
    struct Spis *t;
    int cnt=0,n;
    int lst=900,frst=800;
    
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
       
        if (lst==newt)
        {
            newt=frst;
            t->info=newt;
            (*end) -> next=t;
            *end=t;
        }
           else
            {
                t->info=newt;
                (*end) -> next=t;
                *end=t;
                
            }
        
        if (cnt==0)
        {
            frst=newt;
        }
        cnt++;
        lst=newt;
    }
    }
    
}


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



int main()
{
    struct Spis *begin, *end, *t;
    t = (struct Spis*)malloc(sizeof(struct Spis));
    begin=end=t;
    
    int n,size_;
        while (1)
        {   printf("Choose from these items:\n");
            printf("create 1; enter 2; end 3\n");
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
                    
                case 3: return 0;
                
                default: printf("Incorrect number entered.\n");
                    printf("Try again:\n");
            }
            
            
         }
    
   
    
    return 0;
}
