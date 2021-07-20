//
//  main.c
//  Пузырек
//
//  Created by Dasha Neyzhmak on 10/15/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>

//int main(int argc, const char * argv[]) {
   // Функция сортировки прямым обменом (метод "пузырька")
    void bubbleSort(int *num, int size)
    {
      // Для всех элементов
      for (int i = 0; i < size - 1; i++)
      {
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
          if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
          {
            int temp = num[j - 1]; // меняем их местами
            num[j - 1] = num[j];
            num[j] = temp;
          }
        }
      }
    }
    int main()
    {
      int a[10]; // Объявляем массив из 10 элементов
      // Вводим значения элементов массива
      for (int i = 0; i < 10; i++)
      {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
      }
      bubbleSort(a, 10);  // вызываем функцию сортировки
      // Выводим отсортированные элементы массива
      for (int i = 0; i<10; i++)
        printf("%d ", a[i]);
    return 0;
}
