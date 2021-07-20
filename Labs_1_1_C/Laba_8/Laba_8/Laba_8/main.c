//
//  main.c
//  Laba_8
//
//  Created by Dasha Neyzhmak on 10/28/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.

//Ввести массив структур в соответствии с вариантом.
//Рассортировать массив в алфавитном порядке по первому полю, входящему в структуру.

//В программе реализовать меню:
//+Ввод массива структур;
//+Сортировка массива структ ур;
//+Поиск в массиве структур по заданному параметру;
//+Изменение заданной структуры;
//+Удаление структуры из массива;
//+Вывод на экран массива структур;
//+Выход.

//Структура «Покупатель»: фамилия, имя, отчество; домашний адрес; номер телефона; номер кредитной карточки.


#include <stdio.h>
#include <string.h>
#define N 2
//структура
struct customer
{   char surname[30];
    char name[20];
    char patronymic[20];//отчество
    char home[30];
    char telephone[10];
    char card[10];
};

struct customer mas[30],t; //объвляем глобальный массив структур
struct customer tmp; //объявляем временую переменную структурного типа
struct customer x;
int sch=0;   //Счетчик полных записей
int er;   //Переключатель

void enter_new(void); // ф-ция ввода новой структуры
void change(void); //функция для изменения записи
void out(void);    //ф-ция вывода записей
void delete(void);        //ф-ция удаления записи
void find(void);  //ф-ция поиска
void sorting(void);  //ф-ция сортировки
void dop_zadanie(void);

int main()
{
    int n;
    
    while(1)
    {
    printf ("Choose point:\n");
        printf("1.Enter a new array.\n");
        printf("2.Change the array.\n");
        printf("3.Structure inference.\n");
        printf("4.Delete record.\n");
        printf("5.Find.\n");
        printf("6.Sorting.\n");
        printf("7.Exit.\n");
        printf("8.dop_zadanie\n");
    scanf("%d",&n);
    
    switch (n)
    {
        case 1: enter_new();
            break;
        case 2: change();
            break;
        case 3: out();
            break;
        case 4: delete() ;
            break;
        case 5: find();
             break;
        case 6: sorting();
            break;
        case 7: return 0;
        case 8: dop_zadanie();
            break;
    }
        printf("\n");
    }
    return 0;
}


void enter_new()
{    //printf("The number of the entry you want to enter: \n");//выводим номер записи
     //scanf("%d",&sch);
    
    if(sch<30) //вводим новую запись только, если счетчик полных записей меньше максимального количества записей
    {
        printf("Surname: ");
        scanf("%s",mas[sch].surname);
        printf("Name: ");
        scanf("%s",mas[sch].name);
        printf("Patronymic: ");
        scanf("%s",mas[sch].patronymic);
        printf("Adress of home: ");
        scanf("%s",mas[sch].home);
        printf("Telephone: ");
        scanf("%s",mas[sch].telephone);
        printf("Numer of credit csrd: ");
        scanf("%s",mas[sch].card);
        sch++;
    }
    
    else  printf("The maximum number of records :(");
}

 void change() //функция для изменения записи
{
    int sch;  //номер записи, которую нужно изменить
    int per;
    
    
    printf("Enter number of record:\n");
    scanf("%d",&sch);
    
    while(1)
    {
    
        printf("Сhoose: \n");
        printf("1.Сhange surname.\n");
        printf("2.Сhange name.\n");
        printf("3.Сhange patronymic.\n");
        printf("4.Сhange home address.\n");
        printf("5.Сhange phone number.\n");
        printf("6.Сhange credit card number.\n");
        printf("7.Back to menu.\n");
        
        scanf("%d",&per);
        printf("\n");
        
        switch (per)
        {
                case 1 :
                       printf("Surname: ");
                       scanf("%s",mas[sch].surname);
                       break;
                case 2:
                       printf("Name: ");
                       scanf("%s",mas[sch].name);
                       break;
                case 3:
                       printf("Patronymic: ");
                       scanf("%s",mas[sch].patronymic);
                       break;
                case 4:
                       printf("Adress of home: ");
                       scanf("%s",mas[sch].home);
                       break;
                case 5:
                       printf("Telephone: ");
                       scanf("%s",mas[sch].telephone);
                       break;
                case 6:
                       printf("Numer of credit csrd: ");
                       scanf("%s",mas[sch].card);
                       break;
                
               case 7: main();
         }
    }
}
void out()    //ф-ция вывода записей
{
    int sw;   // переключатель для выбора выводить все записи или одну
    int k;    //номер структуры, кот. надо вывести
    if (sch==0) //если счетсик количества структур равен 0, то выводим, что нет записей
       printf("No records\n");
    else
        printf("Choose: ");
        printf("1.if you want to display ANY record.\t");
        printf("2.if you want to display ALL records.\n");
        scanf("%d",&sw);
    
    if(sw==1)
    {
        printf("Enter the number of the entry you want to output: \n");
        scanf("%d",&k);
        
        printf("Surname: %s\n",mas[k].surname);
        printf("Name: %s\n",mas[k].name);
        printf("Patronymic: %s\n",mas[k].patronymic);
        printf("Adress of home: %s\n",mas[k].home);
        printf("Telephone: %s\n",mas[k].telephone);
        printf("Numer of credit csrd: %s\n",mas[k].card);
 
    }
    
    if(sw==2)
       {
           for(int i=0;i<sch;i++) //sch???????????????????????????
           {
               printf("№%d\n",i);
           printf("Surname: %s\n",mas[i].surname);
           printf("Name: %s\n",mas[i].name);
           printf("Patronymic: %s\n",mas[i].patronymic);
           printf("Adress of home: %s\n",mas[i].home);
           printf("Telephone: %s\n",mas[i].telephone);
           printf("Numer of credit card: %s\n",mas[i].card);
               printf("-------------------------\n");
           }
    
       }
}

void delete()        //ф-ция удаления записи
{
    int del; //номер записи, которую нужно удалить
    
    printf("If you want to delete ALL records, enter 55.\n");
    printf("If you want to delete ONE record\t");
    printf("Enter the number of the record you want to delete: \n");
    scanf("%d",&del);
    
    if (del!=55)
    {       for (int i=(del);i<sch;i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
        {
            mas[i]=mas[i+1]; //замещаем текущую запись следующей за ней
            sch=sch-1; //уменяьшаем счетчик полных записей на 1
        }
    }
        else
            printf("No entry with this number.\n");
    
    
    if (del==55)
    {       for(int i=0;i<30;i++)//цикл по все записям от первой до 30-ой
            mas[i]=tmp; //замещаем каждую структуру в массиве пустой структурой
            sch=0; //счетчик структур обнуляем, т.к. все записи удалены
    }
}

void find()   //ф-ция поиска записей
{   int n;
    char data[15];
    int i_data=0;
    char *istr = NULL;
    if (sch==0)
        printf("No records.");
    else
        printf("Choose:\n");
        printf("1.Find by sorname.\n");
        printf("2.Find by name.\n");
        printf("3.Find by patronymic.\n");
        printf("4.Find by adress of home.\n");
        printf("5.Find by telephone number.\n");
        printf("6.Find by numer of credit card.\n");
        scanf("%d",&n);
    
        
        
                printf("Enter your search data : ");
                scanf("%s", &*data);
                
                for (int i=0;i<sch;i++)
                {
                    if (n==1)
                    {   istr = strstr(mas[i].surname,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
                    if (n==2)
                    {   istr = strstr(mas[i].name,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
                    if (n==3)
                    {   istr = strstr(mas[i].patronymic,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
                    if (n==4)
                    {   istr = strstr(mas[i].home,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
                    if (n==5)
                    {   istr = strstr(mas[i].telephone,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
                    if (n==6)
                    {   istr = strstr(mas[i].card,data);
                        if ( istr != NULL)
                             i_data=i;
                    }
   }
    printf("Surname: %s\n",mas[i_data].surname);
    printf("Name: %s\n",mas[i_data].name);
    printf("Patronymic: %s\n",mas[i_data].patronymic);
    printf("Adress of home: %s\n",mas[i_data].home);
    printf("Telephone: %s\n",mas[i_data].telephone);
    printf("Numer of credit csrd: %s\n",mas[i_data].card);
}

void sorting() //ф-ция сортировки в алфавитном порядке
{
     for (int i=0; i<sch-1; i++)
         for (int j=i+1; j<sch; j++)
             if (strcmp(mas[i].surname, mas[j].surname)>0)
             {
                 t=mas[i];
                 mas[i]=mas[j];
                 mas[j]=t;
                 
             }
    
     printf("Rezultat: \n");
     for (int i=0; i<sch; i++)
     {
         printf("\n");
         printf("№%d\n",i);
         printf("Surname: ");
         puts(mas[i].surname);
         printf("Name: ");
         puts(mas[i].name);
         printf("Patronymic: ");
         puts(mas[i].patronymic);
         printf("Adress of home: ");
         puts(mas[i].home);
         printf("Telephone: ");
         puts(mas[i].telephone);
         printf("Numer of credit card: ");
         puts(mas[i].card);
     }
     }

void dop_zadanie()
{   char l,l2;
    printf("Enter range\n");
    printf("first border: \n");
    scanf("%c",&l);
    scanf("%c",&l);
    printf("last border: ");
    scanf("%c",&l2);
    scanf("%c",&l2);
    
    for (int i=0;i<sch;i++)
    {  if ( l <= *mas[i].name && *mas[i].name<= l2)
       printf("Name: %s\n",mas[i].name);
       }
                    
    }



