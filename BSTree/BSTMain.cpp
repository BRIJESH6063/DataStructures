#include<bits/stdc++.h>
#include"BST.h"
using namespace std ;

int main()
{
    BST b ;
    insertData(b) ;
    printBST(b) ;
    // if(b.hasData(11)) cout << "11 is present in BST" << endl ;
    // else cout << "11 is not present in BST" << endl ;
    // cout << "Hello " << endl ;
    // deleteD(b, 41) ; 
    // cout << "Hello " << endl ;
    // printBST(b) ;
    // cout << "Hello " << endl ;

    BSTNode<int>* node = b.convertToLL() ; BSTNode<int>* head = node ;
    while(node){
        cout << node->data << "  " ;
        node = node->right ;
    }
    cout << endl ;

    return 0 ;
}

/*input --
   6 4 2 5 1 3 10 8 7 9 11 -1
*/