#include<bits/stdc++.h>
#include"constructTrees.h"
using namespace std ;


int main()
{
    int n ; cin >> n ;
    // vector<int> inorder(n) ; vector<int> pretorder(n) ;
    // for(int i=0; i<n; i++) cin >> inorder[i] ;
    // for(int i=0; i<n; i++) cin >> pretorder[i] ;

    vector<int> inorder(n) ; vector<int> postorder(n) ;
    for(int i=0; i<n; i++) cin >> inorder[i] ;
    for(int i=0; i<n; i++) cin >> postorder[i] ;

    // BTNode<int>* root = buildTree(inorder, preorder) ;
    BTNode<int>* root = buildTree2(inorder, postorder) ;

    vector<vector<int>> ans = levelOrder(root) ;
    for(auto x : ans){
        for(auto y : x) cout << y << "  " ;
        cout << endl ;
    }

    cout << "Diameter of tree : " << diameterTree(root) << endl ;
    pair<int, int> p = diameterOptimised(root) ;
    cout << "Height : " << p.first << " Diameter : " << p.second << endl ;

    // fiding path to node 
    vector<int> v ;
    if(getPath(root, 12, v)){
        cout << "Path is : " ;
        for(auto x : v) cout << x << " " ;
        cout << endl ;
    }
    else cout << "Path not available." << endl ;

    return 0 ;
}

/* 
   input inorder postorder 
   7
   4 2 5 1 6 3 7
   4 5 2 6 7 3 1
*/


/*
        
*/