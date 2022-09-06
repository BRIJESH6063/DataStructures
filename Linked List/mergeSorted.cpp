#include<bits/stdc++.h>
#include"MergeTwoSorted.h"
using namespace std ;

int main()
{
    Node *head1 = TakeInputTail() ;
    Node *head2 = TakeInputTail() ;
    PrintList(head1) ;
    PrintList(head2) ;
    // Node* head = MergeTwoSorted(head1, head2) ;
    // PrintList(head) ;

    Node* head = MergeSortedRec(head1, head2) ;
    PrintList(head) ;

    return 0 ;

}