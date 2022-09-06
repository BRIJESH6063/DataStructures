#include<bits/stdc++.h>
#include"DoublyLL.cpp"
using namespace std ;

Node * TakeInputTail(Node* &head, Node* &tail)
{
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            tail = node ; head = node ;
        }
        else{
            tail->next = node ; node->prev = tail ;
            tail = tail->next ;
        }

        cin >> data ;
    }
    return head ;
}

Node * TakeInputHead(Node* &head, Node* tail) 
{ 
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            head = node ; tail = node ;
        }
        else{
            node->next = head ; 
            head->prev = node ; head = node ;
        }

        cin >> data ;
    }
    return head ;
}

void PrintList(Node * print){
    if(print->next == NULL){
        while(print){
            cout << print->data << "-->" ;
            print = print->prev ;
        }
    }
    else if(print->prev == NULL){
        while(print){
            cout << print->data << "-->" ;
            print = print->next ;
        }
    }
    cout << "NULL" << endl ;
}


