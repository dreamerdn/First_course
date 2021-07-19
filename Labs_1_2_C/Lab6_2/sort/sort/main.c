#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10000

void swap(int* arr, int index1, int index2);
void printArray(int* arr, int len);
void fillArrRandom(int* arr, int len);
void selectSort(int* arr, int len);
void insertSort(int* arr, int len);
void bubbleSort(int* arr, int len);
void shellSort(int* arr, int n);


int main()
{
    printf("Skorost' vypolnenija sortirovki 10000 elementov, v sekundah\n");
    //srand(time(0));

    double benchmarkBegin, benchmarkEnd;
    int* arr = (int*)malloc(sizeof(int) * N);

    // sortirovka puzyrkiom
    fillArrRandom(arr, N);

   // benchmarkBegin = get_time();
    bubbleSort(arr, N);
    //benchmarkEnd = get_time();

    printf("\n");
    printf("sortirovka puzyrkiom --- %fs");//, benchmarkEnd - benchmarkBegin);

    // vybornaja sortirovka
    fillArrRandom(arr, N);

   // benchmarkBegin = get_time();
    selectSort(arr, N);
   // benchmarkEnd = get_time();

    printf("\n");
    printf("vybornaja sortirovka --- %fs", benchmarkEnd - benchmarkBegin);

    // sortirovka shella
    fillArrRandom(arr, N);

    //benchmarkBegin = get_time();
    shellSort(arr, N);
    //benchmarkEnd = get_time();

    printf("\n");
    printf("sortirovka shella --- %fs", benchmarkEnd - benchmarkBegin);
}


/*double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart / (double)f.QuadPart;
}
*/
void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void printArray(int* arr, int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void fillArrRandom(int* arr, int len) {
    int i;
    for (i = 0; i < N; i++) {
        arr[i] = rand();
    }
}

void selectSort(int* arr, int len) {
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap(arr, i, j);
            }
        }
    }
}

void bubbleSort(int* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void shellSort(int* arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

