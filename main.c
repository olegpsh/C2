/*
 * Homework 8
 * Pshenichnikov.Oleg
 * 14.02.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 30
#define CNTRMAX 10

void swap(int *a, int* b)               {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void printarr(int *arri, int size)      {
    for (int i = 0; i < size; i++)   {
        printf("%2d ", *arri);
        arri = arri + 1;
    }
    printf("\n");
}
void initarr(int *arr, int maxnumber)   {

    srand(time(NULL));                  // randomize

    for (int i = 0; i < ARRSIZE; i++)   {
        *arr = rand()%maxnumber;
         arr+=1;
    }
}
int *CountingSort(int *a)               {

    int *pcntarr = calloc(CNTRMAX,sizeof(int));                 // index array = zero

    for (int i = 0; i < ARRSIZE; i++)
        pcntarr[*(a + i)]++;

    int j = 0;
    int x = 0;
    while(j < CNTRMAX)   {
        for (int i = x; i < ARRSIZE; i++)   {
            *(a + i) = j;                                       // С одним значением, пробегаю до конца массива, Возможно это не самый оптимальный способ укладывать данные.
        }
        x = x + pcntarr[j];                                     // x - первая позиция, для каждого, ..нового, отсортированного значения.
        j++;
    }

    return a;
}


int main()
{

    int arr[ARRSIZE];
    int *parr = arr;

    initarr(parr, CNTRMAX);                             // диапазон чисeл = 10.
    printf("\nCounting Sort: ");
    printf("\nBefore: ");
    printarr(parr, ARRSIZE);
    printf("After:  ");
    printarr(CountingSort(parr), ARRSIZE);


    return 0;
}
