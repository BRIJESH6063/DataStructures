#include<bits/stdc++.h>
#include"CircularDoublyLL.h"
using namespace std ;

int main()
{ 
    Node* head = NULL ; Node* tail = head ;
    TakeInputTail(head, tail) ;
    PrintListHead(head) ;
    cout << endl ;
    PrintListTail(tail) ;
    
    return 0 ;
}