//
//  main.c
//  L7_6
//
//  Created by Dasha Neyzhmak on 4/25/21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define hashTableSize 10
#define compEQ(a,b) (a == b)
struct Node {
    int data;// данные, хранящиеся в вершине
    struct Node* next; // следующая вершина
};
struct Node** hashTable;
int myhash(int data);
struct Node* insertNode(int data);
void deleteNode(int data);
struct Node* findNode(int data);
void sorted(int, int*);
void swap(int* arr, int index1, int index2);
void bubbleSort(int* arr, int len);
 
int main() {
    int i, maxnum;
    printf("Enter number of elements: ");
    scanf("%d", &maxnum);
    int* a =(int*) malloc(sizeof(int) *maxnum);
    hashTable = (struct Node**)malloc(sizeof(struct Node*) * hashTableSize);
    for (i = 0; i < hashTableSize; i++)
        hashTable[i] = NULL;
    // генерация массива
    for (i = 0; i < maxnum; i++)
        a[i] = rand()%30;
    // заполнение хеш-таблицы элементами массива
    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }
    // поиск элементов массива по хеш-таблице
    for (i = maxnum - 1; i >= 0; i--) {
        findNode(a[i]);
    }
    // вывод значений
    for (i = 0; i < maxnum; i++) {
        printf("%d", a[i]);
        if (i < maxnum - 1) printf("   \n");
    }
    printf("\n");
    // очистка хеш-таблицы
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }
   // bubbleSort(a,maxnum);
    //printf("Sorted:\n");
    sorted(maxnum, a);
    return 0;
}
// хеш-функция размещения вершины
int myhash(int data) {
    return (data % hashTableSize);
}
// функция поиска местоположения и вставки вершины в таблицу
struct Node* insertNode(int data) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node)), * p0;
    int bucket;
    // вставка вершины в начало списка
    bucket = myhash(data);
    if (p == 0) {
        fprintf(stderr, "Нехватка памяти (insertNode)\n");
        exit(1);
    }
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
 
    return p;
}
//функция удаления вершины из таблицы
void deleteNode(int data) {
    struct Node* p0, * p;
    int bucket;
    p0 = 0;
    bucket = myhash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[bucket] = p->next;
    free(p);
}
// функция поиска вершины со значением data
struct Node* findNode(int data) {
    struct Node* p;
    p = hashTable[myhash(data)];
    while (p && !compEQ(p->data, data))
        p = p->next;
    return p;
}
 


void sorted(int size, int* a) {
    int sum=0,m=0,cnt=0;
    for (int i=0;i<size;i++)
    {
        sum=sum+a[i];
    }
    m=sum/size;
    printf("Arithmetic mean: %d \n",m);
    printf("Numbers greater than arithmetic mean:\n");
    for (int i=0;i<size;i++)
    {
        if (a[i]>m)
        {
           printf("%d ",a[i]);
           cnt++;
        }
    }
    printf("\nThe number of numbers is greater than the arithmetic mean: %d\n",cnt);
    printf("\n");
    
}

