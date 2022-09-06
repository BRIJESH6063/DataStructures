#include<bits/stdc++.h>
#include"CircularSinglyList.cpp"
using namespace std ;

Node * TakeInputHead()
{
    Node *head = NULL  ; 
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL) head = node ;
        else{
            node->next = head ; head = node ;
        }
        cin >> data ;
    }
    return head ;
}

Node * TakeInputTail() 
{ 
    Node* head = NULL ; Node* tail = head ;
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            head = node ; tail = node ;
        } 
        else tail->next = node ; 
        tail = node ;
        cin >> data ;
    }
    tail->next = head ;
    return head ;
}

void PrintList(Node * head){
   
    Node* tail = head ; int count = 2 ;
    while(tail != head || count > 0){
        cout << tail->data << "-->" ;
        tail = tail->next ;
        if(tail->next == head) count -- ;
    }
}


