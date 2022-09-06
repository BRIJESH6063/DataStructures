#include<bits/stdc++.h>
#include"MergeSortLL.h"
using namespace std ;

int main()
{
    Node *head = TakeInputTail() ;
    PrintList(head) ;

    head = MergeSortList(head) ;
    PrintList(head) ;
    return 0 ;

}