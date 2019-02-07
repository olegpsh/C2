/*
 *  Pshenichnikov.Oleg 06.02.2019
 *  HomeWork 6
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define STMAX 100
#define STMIN 0

typedef struct Node                 {
    int value;
    struct Node *nextNode;
} node;

typedef struct Stack                {
    node *head;
    int size;
    int maxSize;
    int hash;
}stack;

typedef struct treeNode             {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treenode;

void inOrder(treenode *trn)         {
    if(trn != NULL) {
        inOrder(trn->left);
        printf("%2d ", trn->data);
        inOrder(trn->right);
    }
}

void insertTreeNode(treenode *trnode, int num)    {
//    printf("%d\n", num);
    if(trnode == NULL)  {                           // create and init treenode
        trnode = malloc(sizeof (treenode));
        if(trnode != NULL)  {
            trnode->data = num;
            trnode->left = NULL;
            trnode->right= NULL;
        }

    }    else if (num < trnode->data)        {
        insertTreeNode(trnode->left, num);

    }    else if (num > trnode->data)        {
        insertTreeNode((trnode->right), num);
    }
}

void push(stack *st,  int value)    {

    if (st->size >= st->maxSize) {
            printf("Error stack size");
            return;
        }

    node *tmp = malloc(sizeof(node));
          tmp->value = value;
          tmp->nextNode = st->head;

    st->head = tmp;
    st->size++;
    st->hash = st->hash + value;

}

void PrintStack(stack *st)          {
    node *current = st->head;
    while(current != NULL)    {
        printf("%d ", current->value);
        current = current->nextNode;
    }
}

stack* initStack ()                 {
    stack *s = malloc((sizeof (node)));
    s->head = NULL;
    s->size = STMIN;
    s->maxSize = STMAX;
    s->hash = 0;
    return s;
}

int main()
{
//  1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
//
//  с учётом прошлых замечаний - использую динамические данные (а не массив) и избавился от глобальных переменных.

    stack *s = initStack();
    char arr[] = "$uperMegaDruperFr@z@";

    int i = 0;
    while(arr[i] != '\0')   {
        push(s, arr[i]);    i++;
    }

    PrintStack(s);
    printf("\nhash -> %d \n\n", s->hash);
    free(s);

// 2. Переписать программу, реализующее двоичное дерево поиска.
//    а) Добавить в него обход дерева различными способами;
//    б) Реализовать поиск в двоичном дереве поиска;
//
//    метод insert, не заработал для всего массива, к сожалению.
//    вижу только один элемент дерева (root), а ни весь массив.
//    ошибку не не нашел, к сожалению. Может вы меня направите, где я что-то не до понял (не до делал).

    int arrtree[] = {10, 7, 9, 12, 6, 14, 11, 3, 4};
    treenode *root = malloc(sizeof (treenode));
    root->data = arrtree[0];
    root->left = NULL;
    root->right= NULL;

    for (int i = 0; i < 9; ++i) {
        insertTreeNode(root, arrtree[i]);
    }
    inOrder(root);
    printf("\n");
    return 0;
}
