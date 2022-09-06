#include<bits/stdc++.h>
using namespace std ;

class Node {
    public :
        int data ;
        Node* prev ; Node* next ;
        Node(int data){
            this->data = data ;
            this->prev = NULL ; this->next = NULL ;
        }
} ;

