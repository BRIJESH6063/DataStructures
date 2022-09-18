#include<bits/stdc++.h>
#include"BStree.cpp"
using namespace std ;

void insertData(BST &b){
    int data ; cin >> data ;
    while(data != -1) {
        b.insert(data) ; cin >> data ;
    }
}
void printBST(BST b){
    b.printTree() ;
}
void deleteD(BST &b, int data) {
    b.deleteData(data) ;
}

// BSTNode<int>* convert(BST &b){
//     return b.convertToLL() ;
// }
