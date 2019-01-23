#include <stdio.h>
#include <math.h>

/// -------------------------
/// 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

void dec2bin(int x)   {
    if(x != 0 ) {
        dec2bin(x/2);
    }
    printf("%3d", x%2);						//С учётом прошлых замечаний - в данной функции не очень знаю/понимаю как можно сделать вывод из основной функции.
}											// И 2й момент, хотел спросить, на сколько это правильно на входе функции арифметическое выражение ? Криминал ли это ?
/// -------------------------
/// 2. Реализовать функцию возведения числа a в степень b:
/// b. рекурсивно;
int processes = 0;
int powAB(int A, int B) {

        if(B == 0) return 1;
        if(A >  0) {
            processes++;
            return A * powAB(A, B-1);
        }

}
/// 2. Реализовать функцию возведения числа a в степень b:
/// c. *рекурсивно, используя свойство чётности степени.
int operation = 0;
int fastpowAB(int A, int B) {

    if(B == 0) return 1;
    if(B%2 == 0)    {
        operation++;
        return fastpowAB(A*A, B/2);
    }
    else {
        operation++;
        return A * fastpowAB(A, B-1);
    }
}


int main()  {

    int decnum = 16;
    printf("Decimal number %d binary: \n", decnum);
    dec2bin(decnum);
    printf("\n\n");

    int N = 2; int K = 10;                          // общие переменные, для двух функций, для более явного сравнения количества операций

    printf("    pow(%d, %d) = %d ", N, K,     powAB(N, K));
    printf("\noperation = %d\n\n", processes);

    printf("fastpow(%d, %d) = %d ", N, K, fastpowAB(N, K));
    printf("\noperation = %d\n\n", operation);


    return 0;
}
