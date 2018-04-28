#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "liner_list.h"
using namespace std;

bool IsEmpty(List L)
{
    /*
    if(L->next == NULL)
        return true;
    return false;
    */
    return L->next == NULL;
}

List MakeEmpty(List L)
{
    L->next = NULL;
    return L;
}

bool IsLast(List L)
{
    if(L->next == NULL)
        return true;
    return false;
}

void InsertList(Position P, List L, ElementType X)
{
    Position tmpcell;

    tmpcell = (Node*)malloc(sizeof(struct Node));
    if(tmpcell == NULL)
        cout<<"Error!"<<endl;
    tmpcell->data = X;
    tmpcell->next = P->next;
    P->next = tmpcell;
}








