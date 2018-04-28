#include "liner_list.h"
#include <iostream>
using namespace std;

int main()
{
    List L;
    Position P = L;
    for(int i=0; i<10; i++) {
        InsertList(P,L,i);
        P = P->next;
    }

    Position ptr = L->next;
    while(ptr != NULL) {
        cout<<ptr->data<<"->"<<endl;
        //ptr = ptr->next;
    }
    return 0;
}
