#include<bits/stdc++.h>
#include"BSTree.h"
using namespace std ;

int main()
{
    // BSTNode<int>* root = takeInputLevelWise() ;
    // vector<vector<int>> v = levelOrder(root) ;
    // for(auto x : v){
    //     for(auto y : x) cout << y << " " ;
    //     cout << endl ;
    // }
    int n ; cin >> n ; vector<int> v(n) ;
    for(int i=0; i<n; i++) cin >> v[i] ;
    BSTNode<int>* root = sortedArrayToBST(v) ;

    if(searchBST(root, 7)) cout << "7 is present in the BS tree." << endl ;
    else cout << "7 is not present in the BS tree." << endl ;

    if(findMin(root) == -1) cout << "BST is Empty. " << endl ;
    else cout << "The Min value of BST is : " << findMin(root) << endl ;
    if(findMax(root) == -1) cout << "BST is Empty. " << endl ;
    else cout << "The Max value of BST is : " << findMax(root) << endl ;

    cout << "Range Sum of BST. " << rangeSumBST(root, 2, 6) << endl ;
    if(isValidBST(root)) cout << "This is a valid BST." << endl ;
    else cout << "This is not a valid BST." << endl ;


    return 0 ;
}

/*
   input --
   4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
   1 2 3 4 5 6 7 8 9  sortedArrBST input


   1 2 3 4 5 6 7 (sorted) -> BST mid = root 
*/