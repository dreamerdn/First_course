//Даны три файла целых чисел одинакового размера с именами NameA, NameB и NameC.
//Создать новый файл с именем NameD, в который записать максимальные элементы исходных файлов
//с одним и тем же номером: max(A0, B0, C0),max( A1, B1, C1), max(A2, B2, C2), ...

#include <stdio.h>
int a,n;
void Acheсk ();
FILE* f1, * f2, *f3, *f4;
int n1[3],n2[3],n3[3],n4[3];
int main(int argc, const char * argv[]) {
    
    
    //СОЗДАНИЕ ФАЙЛА NameA
    if (!(f1 = fopen("NameA.txt", "w+t")))
    // w+: Открыть файл для чтения и записи. Если файл существует, то его содержимое теряется.
    //t: Открыть файл в текстовом режиме.
    {
        printf("Cant make a file\n");
        return 0;
    }
    printf("NameA\n");
   //ввод строк в NameA
    
    for (int i = 0; i < 3; i++)
    {
        printf("Vvedite stroky nomer %d\n", i+1);
        Acheсk ();
        n1[i]=a;
        fprintf(f1, "%d\n", n1[i]);
    }
    
  
    
  //СОЗДАНИЕ ФАЙЛА NameB
     if (!(f2 = fopen("NameB.txt", "w+t")))
     {
         printf("Cant make a file\n");
         return 0;
     }
    printf("NameB\n");
    //ввод строк в NameB
     for (int i = 0; i < 3; i++)
     {   printf("Vvedite stroky nomer %d\n", i+1);
         Acheсk ();
         n2[i]=a;
         fprintf(f2, "%d\n", n2[i]);
     }

    
    //СОЗДАНИЕ ФАЙЛА NameC
     if (!(f3 = fopen("NameC.txt", "w+t")))
    {
         printf("Cant make a file\n");
         return 0;
     }
    printf("NameC\n");
    //ввод строк в NameC
    for (int i = 0; i < 3; i++)
     {  printf("Vvedite stroky nomer %d\n", i+1);
         Acheсk ();
         n3[i]=a;
        fprintf(f3, "%d\n", n3[i]);
     }
    
    
   fseek(f1, 0, SEEK_SET);
//Ее основное назначение — поддерживать операции ввода/ вывода по произвольному адресу.
   fseek(f2, 0, SEEK_SET);
   fseek(f3, 0, SEEK_SET);
    
    
   //СОЗДАНИЕ ФАЙЛА NameD
    if (!(f4 = fopen("NameD.txt", "w+t")))
    {
        printf("Cant make a file\n");
        return 0;
    }
    
   for (int i=0; i<3; i++)
    {
        fscanf(f1, "%d", &n1[i]);
        fscanf(f2, "%d", &n2[i]);
        fscanf(f3, "%d", &n3[i]);
    
        if (n1[i]<=n2[i] && n2[i]<=n3[i])
        {
            fprintf(f4, "%d", n3[i]);
            n4[i]=n3[i];
        }
        else
            if (n2[i]<=n1[i] && n1[i]<=n3[i])
            {
            fprintf(f4, "%d", n3[i]);
            n4[i]=n3[i];
            }
        else
            if (n2[i]<=n3[i] && n3[i]<=n1[i])
            {
            fprintf(f4, "%d", n1[i]);
            n4[i]=n1[i];
            }
        else
            if (n3[i]<=n2[i] && n2[i]<=n1[i])
            {
            fprintf(f4, "%d", n1[i]);
            n4[i]=n1[i];
                
            }
        else
            if (n1[i]<=n3[i] && n3[i]<=n2[i])
            {
            fprintf(f4, "%d", n2[i]);
            n4[i]=n2[i];
            }
        else
            if (n3[i]<=n1[i] && n1[i]<=n2[i])
            {
            fprintf(f4, "%d", n2[i]);
            n4[i]=n2[i];
            }
    }
    

    fclose(f1);
    fclose(f2);
    fclose(f3);
    for (int i=0; i<3; i++)
    {
        fscanf(f4, "%d", &n4[i]);
        printf("NameD: %d\n", n4[i]);
    }
    fclose(f4);
    
    return 0;
}


void Acheсk ()
{
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
