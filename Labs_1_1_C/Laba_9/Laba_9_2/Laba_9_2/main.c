//№9_2_файлы
//ошибка выхода после процедуры в меню и из меню прекращения программы
//как работать с записанной информацией в файле
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
FILE* fl;

void created_new_file();
void new_file(); //ф-ция создания нового файла
void enter_new(); //ф-ция ввода новой структуры
void out();    //ф-ция вывода записей
void find_r();  //ф-ция поиска


int main()
{   int n;
    
    while(1)
    {
    printf ("Choose point:\n");
        printf("1.Enter a new file.\n");
        printf("2.Enter a new array.\n");
        printf("3.Structure inference.\n");
        printf("4.Find.\n");
        printf("5.Exit.\n");
    scanf("%d",&n);
    
    switch (n)
    {   case 1: created_new_file();
            break;
        case 2: enter_new();
            break;
        case 3: out();
            break;
        case 4: find_r();
            break;
        case 5: return 0;
            default: printf("Check the entered data.\n");
    }
        printf("\n");
        
    }
    
    return 0;
}

void created_new_file()
{
    char fname[15];
    printf("File name\n");
    gets(fname);
    gets(fname);
     if (!(fl = fopen(fname, "w+t")))
       {
           printf("Cant make a file\n");
       }
    else
        printf("File created ");
    fclose(fl);
    return;
}

void new_file()
{
    char fname[15];
    printf("Название файла\n");
    gets(fname);
    gets(fname);
     if (!(fl = fopen(fname, "a")))
       {
           printf("Cant make a file\n");
       }
}

void enter_new()
{    
    new_file();
    
    int n=0;
    while (1)
    {
        printf("1.New record\n");
        printf("2.meny\n");
        scanf("%d",&n);
        
        if (n==1)
        {
        printf("Surname: ");
        scanf("%s",mas[sch].surname);
        fprintf(fl, "%s\n",mas[sch].surname);
        printf("Name: ");
        scanf("%s",mas[sch].name);
        fprintf(fl, "%s\n",mas[sch].name);
        printf("Patronymic: ");
        scanf("%s",mas[sch].patronymic);
        fprintf(fl, "%s\n",mas[sch].patronymic);
        printf("Adress of home: ");
        scanf("%s",mas[sch].home);
        fprintf(fl, "%s\n",mas[sch].home);
        printf("Telephone: ");
        scanf("%s",mas[sch].telephone);
        fprintf(fl, "%s\n",mas[sch].telephone);
        printf("Numer of credit csrd: ");
        scanf("%s",mas[sch].card);
        fprintf(fl, "%s\n",mas[sch].card);
        sch++;
            if(sch==30)
            {
                printf("This was the maximum number of entries");
                printf("\n");
                main();
            }
        }
        
            if (n==2)
            {
                fclose(fl);
                main();
            }
    
    }
}
 
void out()    //ф-ция вывода записей
{
    int sw;   // переключатель для выбора выводить все записи или одну
    int k;    //номер структуры, кот. надо вывести
    
    new_file();
       
    if (sch==0) //если счетсик количества структур равен 0, то выводим, что нет записей
    {
        printf("No records\n");
        printf("\n");
        main();
    }
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
           for(int i=0;i<sch;i++)
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
    fclose(fl);
}


void find_r()   //ф-ция поиска записей
{   int n;
    char data[15];
    int i_data=0;
    char *istr = NULL;
    
    new_file();
    
    if (sch!=0)
    {
        printf("Choose:\n");
        printf("1.Find by sorname.\n");
        printf("2.Find by name.\n");
        printf("3.Find by patronymic.\n");
        printf("4.Find by adress of home.\n");
        printf("5.Find by telephone number.\n");
        printf("6.Find by numer of credit card.\n");
        scanf("%d",&n);
    }
    else
     if (sch==0)
     {
         printf("No records.\n");
         printf("\n");
         main();
     }
    
     //n=0;
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
    
    fclose(fl);
}





