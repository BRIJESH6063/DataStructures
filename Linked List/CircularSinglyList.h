#include<bits/stdc++.h>
#include"CircularSinglyList.cpp"
using namespace std ;

Node * TakeInputTail()
{
    Node *head = NULL  ; Node *tail = NULL ;
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
    tail->next = head ;
    return head ;
}

Node * TakeInputHead(Node* &head, Node* tail) 
{ 
    Node* head = NULL ; Node* tail = NULL ;
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
    tail->next = head ;
    return head ;
}

void PrintList(Node * head){
   
    Node* tail = head ;
    while(head->next != tail){
        cout << head->data << "-->" ;
        head = head->next ;
    }
    cout << "NULL" << endl ;
}


