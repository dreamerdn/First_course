//
//  main.c
//  сортировка_в алфавитном порядке
//
//  Created by Dasha Neyzhmak on 11/2/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.

//ИЗ ЛАБЫ №8
#include <stdio.h>
//ИЗ ЛАБЫ №8
void sorting() //ф-ция сортировки в алфавитном порядке
{//ИЗ ЛАБЫ №8
for (int i=0; i<sch-1; i++)
for (int j=i+1; j<sch; j++)
if (strcmp(mas[i].surname, mas[j].surname)>0)
{ t=mas[i]; mas[i]=mas[j]; mas[j]=t; }
printf("Rezultat: \n");
for (int i=0; i<sch; i++)
{//ИЗ ЛАБЫ №8
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
