//
//  main.c
//  L7_7


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
void Min(int, int*);
 
int main() {
    int i, num;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int* a =(int*) malloc(sizeof(int) *num);
    hashTable = (struct Node**)malloc(sizeof(struct Node*) * hashTableSize);
    for (i = 0; i < hashTableSize; i++)
        hashTable[i] = NULL;
    // генерация массива
    for (i = 0; i < num; i++)
        a[i] = rand()%35;
    // заполнение хеш-таблицы элементами массива
    for (i = 0; i < num; i++) {
        insertNode(a[i]);
    }
    // поиск элементов массива по хеш-таблице
    for (i = num - 1; i >= 0; i--) {
        findNode(a[i]);
    }
    // вывод значений
    for (i = 0; i < num; i++) {
        printf("%d", a[i]);
        if (i < num - 1) printf("   \n");
    }
    printf("\n");
    // очистка хеш-таблицы
    for (i = num - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }
    Min(num, a);
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
 
void Min(int size, int* a) {
 
    int min = a[0], cnt=0;
    for (int i = 0; i < size; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            cnt=i;
        }
    }
    printf("\n%d", min);
    printf("\n%d\n", cnt+1);
}

