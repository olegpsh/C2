#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float index_mh(int im, float ih)    {
    return im / (ih * ih);
}

int number_max(int x, int y)    {
    if ( x >= y )
        return x;
    return y;
}

void value_exchange_a(int *a, int *b)    {
    int t;

     t = *b;
    *b = *a;
    *a =  t;
}

void value_exchange_b(int *a, int *b)    {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void fquadratic_equation_solver(int a, int b, int c, float *x1, float *x2)   {
    double d;
    d = b * b - 4 * a * c;  // discriminant
    if(a == 0) {
        printf("Sorry, Your equation is not quadratic \n");

    } else if ( d > 0)  {
        *x1 = (-b + sqrt(d)) / 2 * a;
        *x2 = (-b - sqrt(d)) / 2 * a;
        printf("Your equation has two roots, x1 = %f and x2 = %f \n", *x1, *x2);

    } else if ( d == 0) {
        *x1 = -b / (2 * a);
        printf("Your equation has only one root, x1 = %f \n", *x1);

    } else {
        printf("Your equation has no roots \n ");
    }
}

int main()
{
/// 1.Task
///
    printf("\n-------------- Task I:\n");
    int m; float h;

    printf("Input m[kg], for example 80:   ");      scanf("%d", &m);
    printf("Input h[ m], for example 1.80: ");      scanf("%f", &h);

    printf("index_mh = %f\n", index_mh( m, h));

/// 2.Task
    printf("\n-------------- Task II:\n");

    int arr[4];
    srand(time(NULL));

    for (int i = 0; i < 4; ++i) {
        arr[i] = rand();
        printf("arr[%d] = %d \n", i, arr[i]);
    }

    printf("..And the biigges number is = %d\n", number_max(number_max(arr[0],arr[1]) , (number_max(arr[2],arr[3]))));

/// 3.Task
    printf("\n-------------- Task IIIa:\n");
    int var1, var2;

    printf("Enter integer value for the first  variable, var1 = ");     scanf("%d", &var1);
    printf("Enter integer value for the second variable, var2 = ");     scanf("%d", &var2);

    value_exchange_a(&var1, &var2);

    printf("after switch, var1 = %d, var2 = %d\n", var1, var2);

/// 3.Task
    printf("\n-------------- Task IIIb:\n");
    int v1,v2;

    printf("Enter integer value for the first  variable, v1 = ");       scanf("%d", &v1);
    printf("Enter integer value for the second variable, v2 = ");       scanf("%d", &v2);

    value_exchange_b(&v1, &v2);

    printf("after switch, v1 = %d, v2 = %d\n", v1, v2);


/// 4.Task
        printf("\n-------------- Task IV:\n");
    int A, B, C;
    float x1, x2;

    printf("Please, enter A,B,C for square equation 'Ax2 + Bx + C = 0' \n");
    printf("Enter A: ");      scanf("%d", &A);
    printf("Enter B: ");      scanf("%d", &B);
    printf("Enter C: ");      scanf("%d", &C);

    fquadratic_equation_solver(A, B, C, &x1, &x2);

    return 0;
}
