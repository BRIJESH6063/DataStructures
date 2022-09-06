#include<bits/stdc++.h>
#include"CircularDoublyLL.cpp"
using namespace std ;

void TakeInputHead(Node* &head, Node* &tail) 
{
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            head = node ; tail = node ;
        }
        else{
            node->next = head ; head->prev = node ;
            head = node ;
        }
        cin >> data ;
    }
    tail->prev = head ; head->next = tail ;
}

void TakeInputTail(Node* &head, Node* &tail) 
{ 
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            head = node ; tail = node ;
        } 
        else{
            tail->next = node ; node->prev = tail ;
            tail = node ;
        }
        cin >> data ;
    }
    tail->next = head ; head->prev = tail ;
}

void PrintListHead(Node * head){
   
    Node* tail = head ; int count = 2 ;
    while(tail != head || count > 0){
        cout << tail->data << "-->" ;
        tail = tail->next ;
        if(tail->next == head) count -- ;
    }
}

void PrintListTail(Node * tail){
   
    Node* temp = tail ; int count = 2 ;
    while(temp != tail || count > 0){
        cout << temp->data << "-->" ;
        temp = temp->prev ;
        if(temp->next == tail) count -- ;
    }
}

