//Ввести массив вещественных чисел размером п, п вводиться с клавиатуры. Найти его наибольший и наименьший элементы и поменять их местами. Найти сумму и произведение всех элементов массива
#include <stdio.h>

int main(int argc, const char * argv[]) {
int n;
   printf("Введите количество элементов массива: ");
   scanf("%d",&n);
    
    int i,arr[n],min,max,i_min=0,i_max=0,tmp=0;
   for (i=0;i<n;i++){
        printf("arr[%d]:", i);
            scanf("%d", &arr[i]);
          }
    
    max=arr[0];
    min=arr[0];
    
        for(i=0;i<n;i++){
            if (max<arr[i]){
                max=arr[i];
                i_max=i;
            }
            if (min>arr[i]){
                min=arr[i];
                i_min=i;
            }
    }
    printf("\n");
    printf("max: %d i=%d\n",max,i_max);
    printf("min: %d i=%d\n",min,i_min);
    printf("\n");
    tmp=arr[i_max];
    arr[i_max]=arr[i_min];
    arr[i_min]=tmp;
    printf("Вывод массива, наибольший и наименьший элемент поменялись местами:\n");
    for (i=0;i<n;i++){
        
        printf("%d ", arr[i]);
        printf("\n");
    }
    printf("\n");
    int S=0, P=1;
    for (i=0;i<n;i++){
        S+=arr[i];
        P*=arr[i];
    }
    printf("Cумма всех элементов массива: %d\n",S);
    printf("Произведение всех элементов массива: %d\n",P);
    printf("\n");
    return 0;
}
