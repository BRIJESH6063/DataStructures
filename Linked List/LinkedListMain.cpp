#include<bits/stdc++.h>
#include"LinkedListA.h"
using namespace std ;

int main()
{
    // Node * head = new Node(5) ; Node * temp = head ;
    // for(int i=1; i<5; i++) {
    //     Node *node = new Node(5+(i*i)) ;
    //     temp->next = node ; temp = node ; 
    // }
    Node *head = TakeInputTail() ;
    // Node *head2 = TakeInputHead() ;
    PrintList(head) ;
    // PrintList(head2) ;
    InsertAtIth(head, 22, 5) ;
    PrintList(head) ;

    DeleteAtIth(head, 12) ;
    PrintList(head) ;

    return 0 ;

}