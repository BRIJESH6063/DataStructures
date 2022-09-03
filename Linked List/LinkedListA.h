#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std ;

Node * TakeInputTail()
{
    Node * head = NULL ; Node * tail = NULL ; 
    int data ; cin >> data ;
    while(data != -1){
        Node *node = new Node(data) ;
        if(head == NULL){
            tail = node ; head = node ;
        }
        else{
            tail->next = node ; tail = tail->next ;
        }

        cin >> data ;
    }
    return head ;
}

Node * TakeInputHead()
{
    Node * head = NULL ; 
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

void PrintList(Node * head){
    while(head){
        cout << head->data << "-->" ;
        head = head->next ;
    }
    cout << "NULL" << endl ;
}

void InsertAtIth(Node * &head, int data, int i)
{
    Node *node = new Node(data) ; Node *temp = head ;
    if(i <= 0) return ;
    if(i == 1){
        node->next = temp ; head = node ; return ;
    }
    int count = 1 ;
    while(count < i-1 && temp != NULL){
        temp = temp->next ; count ++ ;
    }
    if(temp){
        node->next = temp->next ; temp->next = node ;
    }
}

void DeleteAtIth(Node * &head, int i)
{
    Node *temp = NULL ; Node *temp2 = NULL  ;
    if(i <= 0) return ;
    else if(i == 1) {
        temp = head ; head = head->next ; 
        delete(temp) ; temp = NULL ;
    }
    else {
        int count = 0 ; temp = head ;
        while(count < i-2 && temp){
            temp = temp->next ; count++ ;
        }
        if(temp && temp->next){
            temp2 = temp->next ; temp->next = temp->next->next ;
            delete(temp2) ; temp = NULL ; temp2 = NULL ;
        }
    }
}

