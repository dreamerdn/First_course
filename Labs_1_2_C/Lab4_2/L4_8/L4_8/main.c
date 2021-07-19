//  main.c
//  L4_8
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool is_prime(int i, int n)
{
    if (i * i > n) return true;//если оно простое - возвращаем тру
        else
            if (!(n % i)) return false;//если нет - фолс
    //рекурсивно проверяем, является ли оно простым относительно 2, 3, ... n
                else return is_prime(i + 1, n);
}
 
int main()
{
    int i1 = 2, i2 = i1 + 2;
    int k;//к - кол-во простых ПАР
    printf("Enter the number of pairs: ");
    scanf("%d", &k);
    //счетчик, определяющий кол-во уже выведенных ПАР
    int count = 0;
    while (count != k)
    {
        //если число простое и оно же увеличенное на 2 тоже простое
        if (is_prime(2, i1) && is_prime(2, i2))
        {
           
            printf("%d  %d\n", i1, i2);
            count++;
        }
        i1++;
        i2++;
    }
 
}
