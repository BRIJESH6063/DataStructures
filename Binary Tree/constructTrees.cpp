#include<bits/stdc++.h>
#include"constructTrees.h"
using namespace std ;


int main()
{
    int n ; cin >> n ;
    vector<int> inorder(n) ; vector<int> preorder(n) ;
    for(int i=0; i<n; i++) cin >> inorder[i] ;
    for(int i=0; i<n; i++) cin >> preorder[i] ;

    BTNode<int>* root = buildTree(inorder, preorder) ;

    vector<vector<int>> ans = levelOrder(root) ;
    for(auto x : ans){
        for(auto y : x) cout << y << "  " ;
        cout << endl ;
    }
    return 0 ;
}