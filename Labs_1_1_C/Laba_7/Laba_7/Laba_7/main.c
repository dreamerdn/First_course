//
//  main.c
//  Laba_7
//
//  Created by Dasha Neyzhmak on 10/19/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.

//Создать программу, которая выполняет действия из задания 1 и задания 2. По запросу с клавиатуры, программа выполняет следующие действия:
//Ввести новый массив (динамический);
//Задание 1: 8. Найти в матрице первую строку, все элементы которой равны нулю. Все элементы столбца с таким же номером уменьшить вдвое.
//Вывод массива;
//Задание 2: 8. Напишите программу, которая вводит несколько строк текста и символ поиска и использует функцию strchr, чтобы определить суммарное число вхождений символа в текст.
//Выход.
//В программе должно быть реализовано меню, каждое действие должно быть реализовано в отдельной функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** Creating(int n, int m);
void output (int** mas, int n, int m);
int** Task_1 (int** mas1, int n1, int m1);
void Task_2 ();

int main(int argc, const char * argv[]) {
    int n;
    int size1,size2,size1_1,size2_1;
    int **arr;
//char str[12];
    printf("1.Creating new array.\n");
    printf("2.Task №1.\n");
    printf("3.Output of array.\n");
    printf("4.Task №2.\n");
    printf("5.Exit.\n");
    
    while (1)
    {
    printf("Choose point: ");
    scanf("%d",&n);
    
    switch (n)
    {
        case 1:
            printf("Enter size1 of array:");
            scanf("%d", &size1);
            printf("Enter size2 of array:");
            scanf("%d", &size2);
            arr = Creating(size1,size2);
            size1_1 = size1;
            size2_1 = size2;
            printf("\n");
            break;
            
         case 2:
            Task_1(arr, size1, size2);
            printf("\n");
            break;
            
         case 3:
            output(arr, size1, size2);
            printf("\n");
            break;
            
        case 4:
            //gets (str);
            Task_2();
            
            break;
        
        case 5: return 0;
    }
        printf("\n");
    }
    return 0;
}

int** Creating (int n, int m)
{
    int** a = (int**)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
    }
        for (int i=0; i<n; i++)
        {
        for (int j=0; j<m; j++)
        {
        printf("[%d][%d]:",i,j);
        scanf("%d", &a[i][j]);
        
        }
        }
    return a;
}

void output(int** mas, int n, int m)
{
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
printf("%d\t", mas[i][j]);
}
printf("\n");

}
}

int** Task_1 (int** mas1,int n1, int m1)
{
    int s,nul=0;
       for (int i=0;i<n1;i++)
       {
           s=0;
           for (int j=0;j<m1;j++)
           {
               s+=mas1[i][j];
           }
          
           if (s==0)
               
           {   printf("i:%d sum:%d",i+1,s);
               nul=i;
               for (i=0;i<n1;i++)
               {
                   mas1[i][nul]=(mas1[i][nul]/2);
                   
               }
           }
           else
               printf("String i:%d have other digit other than zero",i+1);
           printf("\n");
        }
    return mas1;
}
       
void Task_2 ()
    {
         char stroka[1024];
         printf ("Enter string: \n");
         gets (stroka);
         gets (stroka);
         char symbol;
           
                printf("Enter the character you are looking for: ");
                rewind(stdin);
                scanf("%c", &symbol);
        
                char *ptr = NULL;
                int tmp = 0;
        
                ptr = strchr(stroka, symbol);
              
                    while (ptr!=NULL)
                    {
                        ptr++;
                        ptr = strchr(ptr, symbol);
                        tmp++;
                    }
                    printf("the number of letter repetition = %d\n", tmp);
               
        }
         
        
    
    
