#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tree
{
    int number;
    struct tree* left;
    struct tree* right;
} TREE;

// Первый узел в дереве
TREE* root;
int count = 0;
// Создать корень дерева
TREE* create_tree(TREE* root);
TREE* add_list(TREE* root);
// Добавить узел
TREE* add_node(int i);
//Поиск по заданному ключу
TREE* search_node(TREE* root);
// Удалить узел дерева
void delete_node(int key);
// Вывести дерево на экран
void print_tree(TREE* t, int level);
void printLevelOrder(TREE* root);
bool isLeaf(TREE* node);
int height(TREE* node);
// Определить число листьев на каждом уровне дерева
int printGivenLevel(TREE* node, int level);
// Очистить память
void clear_memory(TREE* t);

int main()
{
    root = NULL; // Инициализируем корень дерева
    int ch, key;
    //setlocale(LC_ALL, "Rus");
    while (1)
    {
    printf("Выберите действие:\n");
    printf("1. Создать корень дерева.\n");
    printf("2. Добавить узел.\n");
    printf("3. Поиск по заданному ключу.\n");
    printf("4. Удалить узел.\n");
    printf("5. Вывести дерево на экран.\n");
    printf("6. Показать число листьев на каждом уровне дерева.\n");
    printf("7. Очистить память и выйти.\n");

    printf("Ваш выбор? ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1: root = create_tree(root);
            break;
        case 2: add_list(root);
            break;
        case 3: search_node(root);
            break;
        case 4: printf("\n Введите элемент дерева, который нужно удалить: ");
                scanf("%d", &key);
                delete_node(key);
            break;
        case 5: print_tree(root, 0);
            break;
        case 6: printLevelOrder(root);
            break;
        case 7: clear_memory(root);
            return 0;
        default: printf("Вы ввели неверное значение.\n");
    }
    }
return 0;
}

// Создать корень дерева
TREE* create_tree(TREE* root)
{
    int root_ch; // целочисленное значение ключа в корне дерева

    // СОЗДАНИЕ КОРНЯ
    if (root == NULL && count != 1)

    {   printf("Введите целочисленное значение ключа в корне дерева:\n");
        scanf("%d", &root_ch);
        printf("СОЗДАНИЕ ДЕРЕВА...\n Корень дерева - %d\n", root_ch);
        root = add_node(root_ch); // Вызов функции построения листа
        count++;
    }
    add_list(root);
    return root;
}

TREE* add_list(TREE* root)
{
    TREE* Prev = NULL, * t;
    int find;
    int key;

    if (root != NULL)
    { printf("Дерево создано! Можете добавлять отдельные листья.\n");
        // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ
        printf("(Для прекращения ввода ключей введите отрицательное число)\n");
        
        while (1)
        {
            printf("\n Введите ключ.\n");
            printf("Ключ: ");
            scanf("%d", &key);
            if (key < 0) break; // Лист не может быть отрицательным числом
            printf("\n");
            t = root;
            find = 0;
            while (t && !find)
                {
                    Prev = t;
                    if (key == t->number)
                        find = 1;
                    else
                        if (key < t->number)
                            t = t->left;
                        else t = t->right;
                }

            
            if (!find)
            {
                t = add_node(key); // Создаем новый узел и присоединяем его
                if (key < Prev->number)
                Prev->left = t; // либо на левую ветвь,
                else Prev->right = t; // либо на правую ветвь
            }
        }

}
    else printf("Дерево не создано!\n");

return root;
}



// Добавить узел
TREE* add_node(int i)
{
    TREE* t = (TREE*)malloc(sizeof(TREE*));
    t->number = i;
    t->left = t->right = NULL;
return t;
}


//Поиск по заданному ключу
TREE* search_node(TREE* root)
{
    int search; // Ключ, который будем искать
    if (root != NULL)

{
    printf("Введите ключ для поиска: ");
    scanf("%d", &search);
    TREE* srch = root;
    while (srch != NULL && srch->number != search)
{

    if (srch->number > search)
        srch = srch->left;
    else srch = srch->right;
}

    if (srch == NULL)
        printf("Ключ не найден!\n");
    else
        if (srch->number == search)
            printf("Найденный ключ:\n %d.\n", srch->number);
}
else printf("Дерево не создано!\n");
    
return root;
}


// Удалить узел дерева
void delete_node(int key)
{
    TREE* Del, * Prev_Del, * R, * Prev_R; // Del, Prev_Del - удаляемый элемент и его предок;
    // R, Prev_R - элемент, на который заменяется удаленный и его предок;
    Del = root; Prev_Del = NULL;
    // Поиск удаляемого элемента и его предка по ключу key
    
while (Del != NULL && Del->number != key)
{
    Prev_Del = Del;
    if (Del->number > key) Del = Del->left;
    else Del = Del->right;
}
    
    if (Del == NULL)
    { // В дереве такого ключа нет
        puts("\n Такого элемента нет!");
        return;
    }
    
    // Поиск элемента для замены R
    // Если удаляемый элемент имеет одного потомка, или ЛИСТ
    if (Del->right == NULL) R = Del->left;
    else
        if (Del->left == NULL) R = Del->right;
        else
        { // Иначе, ищем самый правый узел в левом поддереве
            Prev_R = Del;
            R = Del->left;
            
            while (R->right != NULL)
            {
                Prev_R = R;
                R = R->right;
            }
            
            // Если удаляемый элемент имеет одного потомка
            if (Prev_R == Del) R->right = Del->right;
            else
            {
                // Если удаляемый элемент имеет двух потомков
                R->right = Del->right;
                Prev_R->right = R->left;
                R->left = Prev_R;
            }
            
        }

    // Устанавливаем связь с предком удаляемого (Prev_Del) и заменой (R):
    if (Prev_Del == NULL)
    {
        root = Prev_Del = R;
    }
    else
        if (Del->number < Prev_Del->number) Prev_Del->left = R;
        else Prev_Del->right = R;
            printf("\n Элемент %d удалён ", Del->number);
    free(Del);
}


// Вывести дерево на экран
void print_tree(TREE* t, int level)
{
    if (root != NULL)
    {
        if (t)
        {   print_tree(t->right, level + 1);
            for (int i = 0; i <= level; i++)
                printf(" ");
                printf("%d\n", t->number);
                print_tree(t->left, level + 1);
        }
    }

else printf("Дерево не создано!\n");
}


int height(TREE* node)
{ //Функция определения высоты дерева (число уровней)
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
            else
            {
                return (rheight + 1);
            }

    }
}

bool isLeaf(TREE* node)
{ //Функция проверки, что узел дерева является листом
    if (!node->left && !node->right)
    {
        return true;
    }

return false;
}


// Определить число листьев на каждом уровне дерева
int printGivenLevel(TREE* node, int level)
{ //Функция подсчета листьев на заданном уровне
    if (node == NULL)
        return 0;
        static int k = 0;
    if (level == 1)
    {
        if (isLeaf(node))
        {
            k++;
        }
    }
    else
        if (level > 1)
        {
            printGivenLevel(node->left, level - 1);
            printGivenLevel(node->right, level - 1);
        }

return k;
}


void printLevelOrder(TREE* root)
{
    int h = height(root); //Количество уровней (высота дерева)
    
    for (int i = 1; i <= h; i++)
    {
        printf("Level %d ", i);
        int curr = printGivenLevel(root, i);
        printf("%d", printGivenLevel(root, i) - curr);
        printf("\n");
    }
}


// Очистить память
void clear_memory(TREE* t)
{
    if (t != NULL)
    {
        clear_memory(t->left);
        clear_memory(t->right);
        free(t);
    }
else printf("Дерево не создано!\n");
}
