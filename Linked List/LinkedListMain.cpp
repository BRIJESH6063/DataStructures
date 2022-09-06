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
    cout << "Length : " << length(head) << "  List : " ; PrintList(head) ;
    // PrintList(head2) ;
    // InsertAtIth(head, 22, 5) ;
    // cout << "Length : " << length(head) << "  List : " ; PrintList(head) ;
    // DeleteAtIth(head, 12) ;
    // cout << "Length : " << length(head) << "  List : " ; PrintList(head) ;

    // if(isPresent(head,23)) cout << "23 is present in the linkedList." << endl ;
    // else cout << "23 is not present in the linkedList." << endl ;

    // if(isPresentRec(head,21)) cout << "21 is present in the linkedList." << endl ;
    // else cout << "21 is not present in the linkedList." << endl ;

    // Node * mid = MidElement(head) ;
    // cout << "Mid Element of LinkedList is : " << mid->data << endl ;

    // Reverse(head) ;
    // cout << "Length : " << length(head) << "  List : " ; PrintList(head) ;

    RemoveKthEnd(head, 3) ;
    cout << "Length : " << length(head) << "  List : " ; PrintList(head) ;

    return 0 ;

}