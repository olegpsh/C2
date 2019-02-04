/*
 * Pshenichnikov Oleg
 * Homework 5
 * 03.02.2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <ctype.h>

#define MAXN 1000
#define T int
#define BIN 2
#define TRUE 1
#define FALSE 0

struct intStack                                   {
    int n;
    int data[MAXN];
};
struct charStack                                  {
    int n;
    char data[MAXN];
};
struct intStack  iStack_dec2bin;
struct intStack  iStack1;   // ()
struct intStack  iStack2;   // {}
struct intStack  iStack3;   // []

int popup(struct intStack *Stack )              {
//    printf("popup. n: %d \n", Stack->n);
    if(Stack->n != -1)
        return Stack->data[Stack->n--];
    else {
        Stack->n--;
        printf("Stack is empty\n");
    }
}
void push(struct intStack *Stack, int data)     {
//    printf("push loop. %d \n", data);
    if( Stack->n < MAXN)  {
        Stack->n++;
        Stack->data[Stack->n] = data;
    }
    else    {
        printf("Stack overflow\n");
    }
}
void decimal2bin(int dec)                       {
//printf("dec: %d \n", dec);
    while (dec > 0) {
             push(&iStack_dec2bin , dec % BIN);
                dec = dec/BIN;
        }
}
void init(struct intStack *Stack)               {
    Stack->n = -1;
}
void brackets(char *tmp)                        {
    switch (tmp[0])
    {
        case '(':
            push(&iStack1, TRUE);
        break;
        case ')':
            popup(&iStack1);
        break;
        case '{':
            push(&iStack2, TRUE);
        break;
        case '}':
            popup(&iStack2);
        break;
        case '[':
            push(&iStack3, TRUE);
        break;
        case ']':
            popup(&iStack3);
        break;

        default:
        break;
    }
}


int main()
{
    init(&iStack_dec2bin);
    init(&iStack1);
    init(&iStack2);
    init(&iStack3);

// 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
    printf("\n1. From decimal to binary \n");

    int decnum = 11;
    printf("Decimal number: %d ", decnum);
    decimal2bin(decnum);

    printf("\nPopup from stack: \n");
    for (int i = iStack_dec2bin.n; i > -1; i--)         // popup from stack
        printf("%2d", popup(&iStack_dec2bin));
    printf("\n");


// 2. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//    Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//  Например: (2+(2*2)) или [2/{5*(4+7)}]   {}(20+30)/[10]]
    printf("\n2. Brackets sequence\n");

    char buf[50] = "[2/{5*(4+7)}]";                    // expration
    for (int i = 0; i < strlen(buf); i++)    {
            brackets(&buf[i]);
    }

    iStack1.n != -1 ? printf("Something wrong with your brackets () \n") :  printf("Brackets is closed in your expression ()\n");
    iStack2.n != -1 ? printf("Something wrong with your brackets {} \n") :  printf("Brackets is closed in your expression {}\n");
    iStack3.n != -1 ? printf("Something wrong with your brackets [] \n") :  printf("Brackets is closed in your expression []\n");

    printf("\n");
    return 0;
}
