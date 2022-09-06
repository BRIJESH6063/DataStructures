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

Node* MergeTwoSorted(Node *head1, Node *head2)
{
    if(head1 == NULL) return head2 ;
    if(head2 == NULL) return head1 ;
    Node *ans = NULL ;
    if(head1->data < head2->data){
        ans = head1 ; head1 = head1-> next ;
    }
    else {
        ans = head2 ; head2 = head2-> next ;
    }
    Node *p = ans ;
    while(head1 && head2){
        if(head1->data < head2->data){
            p->next = head1 ; head1 = head1-> next ;
        }
        else {
            p->next = head2 ; head2 = head2-> next ;
        } 
        p = p->next ;
    }

    if(head1) p->next = head1 ;
    else if(head2) p->next = head2 ;

    return ans ;
}

Node* MergeSortedRec(Node* head1, Node* head2){
    if(head1 == NULL) return head2 ;
    if(head2 == NULL) return head1 ;

    Node* newHead = NULL ;
    if(head1->data < head2->data){
        newHead = head1 ; 
        newHead->next = MergeSortedRec(head1->next, head2) ;
    }
    else {
        newHead = head2 ; 
        newHead->next = MergeSortedRec(head1, head2->next) ;
    }
    return newHead ;
}