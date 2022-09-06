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

Node* MergeSortList(Node* head)
{
    if(head == NULL || head->next == NULL) return head ;
    // break into two part
    Node* slow = head ; Node* fast = head->next ;
    while(fast && fast->next){
        slow = slow->next ;
        fast = fast->next ;
    }
    Node* node = slow->next ; slow->next = NULL ;

    Node* a = MergeSortList(head) ; Node* b = MergeSortList(node) ;
    head = MergeSortedRec(a, b) ;
    return head ;
}