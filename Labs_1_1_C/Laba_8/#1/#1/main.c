#include <stdio.h>

struct student
{ char name[20];
  char fam[30];
  int year;
  int mark[5];
  int average;
};

struct student students[30];
struct student buffer;
int records;
int i, j;

int main()
{
    records=0;
    do
    {
        printf("Student №%d\n", records+1);
        puts("Vvedite familiu: ");
        fflush(stdin);
        gets(students[records].fam);
        puts("Vvedite imya: ");
        fflush(stdin);
        gets(students[records].name);
        puts("Vvedite vozrast: ");
        scanf("%d", &students[records].year);
        for(i=0; i<5; i++)
        {    printf("Vvedite ocenku po ekzamenu №%d ", i+1);
            scanf("%d", &students[records].mark[i]);
        }
        records++;
        puts("Prekratit' rabotu? (1/0)");
        scanf("%d", &i);
    } while(i);
    
    for (i=0; i<records; i++)
    { students[i].average=0;
      for (j=0; j<5; j++)
          students[i].average+=students[i].mark[j];
    }
    
 /*   for (i=0; i<records-1; i++)
        for (j=i; j<records; j++)
            if (students[i].average>students[j].average)
            {  buffer=students[i];
               students[i]=students[j];
               students[j]=buffer;
            }*/

    for (i=0; i<records; i++)
    {
        printf("Student %s %s ", students[i].name, students[i].fam);
        printf(" Vosrast %d ", students[i].year);
        printf(" Sr. ball %d \n", students[i].average);
    }
    //getch();
    return 0;
}
