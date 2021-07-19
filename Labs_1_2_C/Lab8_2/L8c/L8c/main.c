//
//  main.c
//  L8_8
//
//  Created by Dasha Neyzhmak on 7.05.21.
//  Copyright © 2021 Dasha Neyzhmak. All rights reserved.
//

#include <string.h>

//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct AdjListNode

{

int dest;

int weight;

struct AdjListNode* next;

};

struct AdjList

{

struct AdjListNode* head;

};

struct Graph

{

int V;

struct AdjList* array;

};

struct AdjListNode* newAdjListNode(int, int);

struct Graph* createGraph(int);

void addEdge(struct Graph*, int, int, int);

void printGraph(struct Graph*);

void delEdge(struct Graph*, int);

void delNode(struct Graph*, int);

void printAdjMatrix(struct Graph*);

void printMenu(void);

int* arrayDelNode;

struct AdjListNode* newAdjListNode(int dest, int weight)

{

struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode*));

newNode->dest = dest;

newNode->weight = weight;

newNode->next = NULL;

return newNode;

}

struct Graph* createGraph(int V)

{

struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

graph->V = V;

graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

int i;

for (i = 0; i < V; ++i)

graph->array[i].head = NULL;

arrayDelNode = (int*)malloc(V * sizeof(int));

memset(arrayDelNode, 0, V * sizeof(int));

return graph;

}

void addEdge(struct Graph* graph, int src, int dest, int weight)

{

struct AdjListNode* newNode = newAdjListNode(dest, weight);

newNode->next = graph->array[src].head;

graph->array[src].head = newNode;

newNode = newAdjListNode(src, weight);

newNode->next = graph->array[dest].head;

graph->array[dest].head = newNode;

}

void printGraph(struct Graph* graph)

{

int v;

for (v = 0; v < graph->V; ++v)

{

struct AdjListNode* pCrawl = graph->array[v].head;

if (arrayDelNode[v]) continue;

printf("\nСписок смежности из вершины %d\n", v);

while (pCrawl)

{

printf("Из вершины %d ребро под номером %d соединяется с вершиной %d;\n", v, pCrawl->weight, pCrawl->dest);

pCrawl = pCrawl->next;

}

printf("\n");

}

}

void delEdge(struct Graph* graph, int nEdge)

{

struct AdjListNode* del, * prevDel;

int counter = 0;

prevDel = NULL;

    
del = graph->array[0].head;
while (del && del->weight != nEdge)
{
prevDel = del;
del = del->next;
}
graph->array[0].head = del->next;
free(del);
counter++;

    
    
del = graph->array[2].head;
while (del && del->weight != nEdge)
{
prevDel = del;
del = del->next;
}
prevDel->next = del->next;
free(del);
counter++;

    
del = graph->array[2].head;
while (del && del->weight != nEdge)
{
prevDel = del;
del = del->next;
}
prevDel->next = del->next;
free(del);
counter++;

    
del = graph->array[4].head;

while (del && del->weight != nEdge)

{

prevDel = del;

del = del->next;

}

prevDel->next = del->next;

free(del);

counter++;

if (counter)

printf("Рёбра %i удалены!\n", nEdge);

}

void delNode(struct Graph* graph, int nNode)

{

struct AdjListNode* tmp, * del, * prevDel;

if (nNode >= 0 && nNode < graph->V)

{

if (arrayDelNode[nNode]) {

printf("Вершина уже удалена!\n");

return;

}

if (graph->array[nNode].head) {

del = graph->array[nNode].head;

while (del) {

tmp = del;

del = del->next;

free(tmp);

}

}

arrayDelNode[nNode] = 1;

for (int i = 0; i < graph->V; i++) {

prevDel = NULL;

if (arrayDelNode[i]) continue;

del = graph->array[i].head;

while (del && del->dest != nNode) {

prevDel = del;

del = del->next;

}

if (del) {

if (prevDel) {

tmp = del;

prevDel->next = del->next;

free(del);

}

else {

tmp = del;

graph->array[i].head = del->next;

free(del);

}

}

}printf("Вершина %i удалена\n", nNode);

}

else

printf("Такой вершины не существует!\n");

}

void printAdjMatrix(struct Graph* graph)

{

if (graph)

{

int size = graph->V;

int adjMatrix[7][7];

for (int i = 0; i < graph->V; i++)

for (int j = 0; j < graph->V; j++)

adjMatrix[i][j] = 0;

for (int i = 0; i < size; i++) {

struct AdjListNode* node = graph->array[i].head;

if (arrayDelNode[i]) continue;

while (node) {

adjMatrix[i][node->dest] = node->weight;

node = node->next;

}

}

printf("Матрица смежности:\n");

printf(" ");

for (int i = 0; i < size; i++) {

if (arrayDelNode[i]) continue;

printf("%i ", i);

}

printf("\n");

for (int i = 0; i < size; i++) {

if (arrayDelNode[i]) continue;

printf("%i ", i);

for (int j = 0; j < size; j++) {

if (arrayDelNode[j]) continue;

printf("%i ", adjMatrix[i][j]);

}

printf("\n");

}

}

else printf("Граф не существует!\n");

}






void printMenu()

{

setlocale(LC_ALL, "Rus");

printf("\n"

"МЕНЮ:\n"

"1) Создать граф\n"

"2) Удалить рёбра с номером 8\n"

"3) Удалить вершину с номером 5\n"

"4) Вывести граф на экран\n"

"5) Вывести матрицу смежности\n"

"6) Выход\n"

"\n");

}

int main()

{

printMenu();

int choice;

int nNode = 5;

int nEdge = 8;

struct Graph* graph = NULL;

printf("Ваш выбор: ");

scanf("%i", &choice);

while (choice) {

switch (choice) {

case 1:

{

if (!graph) {

graph = createGraph(7);

addEdge(graph, 0, 1, 5);

addEdge(graph, 0, 2, 8);

addEdge(graph, 1, 3, 12);

addEdge(graph, 1, 5, 9);

addEdge(graph, 2, 4, 8);

addEdge(graph, 2, 5, 4);

addEdge(graph, 2, 6, 2);

addEdge(graph, 3, 4, 3);

addEdge(graph, 3, 5, 6);

addEdge(graph, 4, 6, 7);

printf("Граф создан!");

}

else

printf("Граф уже существует!\n");

}

break;

case 2:

{

if (graph)

{

if (nEdge == 8)

{

delEdge(graph, nEdge);

nEdge++;

}

else printf("Ребро уже удалено!");

}

else

printf("Граф не существует!\n");

}

break;

case 3:

{

if (graph)

{

if (nNode == 5)

{

delNode(graph, nNode);

nNode++;

}

else printf("Вершина уже удалена!");

}

else

printf("Граф не существует!\n");

}

break;

case 4:

if (graph)

{

printGraph(graph);

}

else

printf("Граф не существует!\n");

break;

case 5:

printAdjMatrix(graph);

break;

case 6: return 0;

}

printMenu();

printf("Ваш выбор: ");

scanf("%i", &choice);

}

}
