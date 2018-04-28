#ifndef LINER_LIST_H_INCLUDED
#define LINER_LIST_H_INCLUDED

#define ElementType int

struct Node {
    ElementType data;
    Node * next;
};
typedef Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

bool IsEmpty(List L);
List MakeEmpty(List L);
void InsertList(Position P, List L, ElementType X);


#endif // LINER_LIST_H_INCLUDED
