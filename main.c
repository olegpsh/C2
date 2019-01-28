/*
 * 29.01.2019
 * Pshenichnikov Oleg
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 25

void swap(int* a, int* b)   { 
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void create_arr(int *a)     {
    srand ( time(NULL));
           for (int i = 0; i < MAXNUM; ++i) {
               a[i] = rand() % 100;
//               printf("%d, ", a[i]);
           }
           printf("\n");
}
void print_arr(int *a)      {
    for (int i = 0; i < MAXNUM; ++i) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

void sort_Bubble(int *arr ) {
//int counter = 0;
    for(int i = 0; i < MAXNUM; i++)
        for(int j = 0; j < MAXNUM - 1; j++)
            if (arr[j] > arr[j + 1])
            {
//              counter++
                swap(&arr[j], &arr[j + 1]);
            }
//        printf("Bubble swap: %d\n", counter);
}


//  2. *Реализовать шейкерную сортировку.
//  рекурсия на основе задачи ЕГЭ - «подъём» & «спуск»

int MRL(int l, int r, int *a);          // Move Right->Left function init()
int MLR(int l, int r, int *a);          // Move Left->Right function init()

int MLR(int l, int r, int *a)   {       // Search shaker, move from Left to Right,  (MAX number)
//    printf("l: %d  r: %d\t", l, r);
        for (int i = l; i < r; i++) {
            if (a[r] < a[i])
                swap(&a[i], &a[r]);
        }
        print_arr(a);
        r--;
        if( l != r) {            MRL(l, r, a);          }
        else        {            return 1;              }
}

int MRL(int l, int r, int *a)   {       // Search shaker, move from Right to Left,  (MIN number)
//    printf("l: %d  r: %d\t", l, r);
        for (int i = r; i > l; i--) {
            if (a[l] > a[i])
                swap(&a[l], &a[i]);
        }
        print_arr(a);
        l++;
        if( l != r) {            MLR(l, r, a);          }
        else        {            return 1;              }
}

// 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
//    Функция возвращает индекс найденного элемента или -1, если элемент не найден.
int BinaryAlgorithm (int L, int R, int V, int *a) {
    int M = L + (R - L)/2;

    while (( L <= R ) && (a[M] != V))    {
        if ( a[M] < V)
            L = M + 1;
        R = M - 1;
        M = L + (R + L)/2;
    }
    return (a[M] == V ) ? M : -1;
}

int main()
{
    int *parr;      //  0   1   2   3   4   5   6   7   8   9  10  11  12  13 14  15  16  17  18  19  20  21  22  23  24
    int arr[MAXNUM] = {76, 19, 93, 33, 16, 34, 63, 21, 44, 16, 91, 88, 82, 9, 76, 82, 75, 17, 83, 51, 19, 83, 11, 39, 71};
    parr = &arr[0];

//    create_arr(parr);
//    sort_Bubble(parr);
//    puts("Array after sort");
    print_arr(parr);
    printf("\n");

    int Left_i  = 0;                                // Left  (min) array index
    int Right_i = sizeof(arr)/sizeof(arr[0]) - 1;   // Right (max) array index

    MLR(Left_i, Right_i, parr);                     // first move, from the left to the right ( MLR )
    puts("\n Array after 'Shaker' sort: ");
    print_arr(parr);
    printf("\n");


    int Value = arr[11];                            // value
    printf("We try to find: %d\n", Value);
    printf ("Value of index array: %d \n", BinaryAlgorithm(Left_i, Right_i, Value, parr));


    return 0;
}


