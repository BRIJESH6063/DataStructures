#include<bits/stdc++.h>
#include"Btree.cpp"
using namespace std ;

// construct tree from preorder and inorder  
BTNode<int>* buildTreeHelper(vector<int> inorder, vector<int> preorder, int inS, int inE, int preS, int preE)
{
    if(inS > inE) return NULL ;
    int data = preorder[preS] ;

    int LeftInS = inS ;
    int rootIndex = -1 ;
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i] == data) rootIndex = i ;
    }
    int LeftInE  = rootIndex - 1; 
    int LeftPreS = preS + 1 ; 
    // leftInE - leftInS = leftPreE - leftPreS 
    int LeftPreE = LeftInE - LeftInS + LeftPreS ; 

    int RightInS = rootIndex + 1 ; 
    int RightInE = inE; 
    int RightPreS = LeftPreE + 1 ; 
    int RightPreE = preE ; 

    BTNode<int>* root = new BTNode<int>(data) ;
    root->left  = buildTreeHelper(inorder, preorder, LeftInS, LeftInE, LeftPreS, LeftPreE) ;
    root->right = buildTreeHelper(inorder, preorder, RightInS, RightInE, RightPreS, RightPreE) ;

    return root ;
}
BTNode<int>* buildTree(vector<int> inorder, vector<int> preorder)
{
    int n = inorder.size() ;
    return buildTreeHelper(inorder, preorder, 0, n-1, 0, n-1) ;
}


vector<vector<int>> levelOrder(BTNode<int>* root)
{
    vector<vector<int>> v ; vector<int> temp ;
    queue<BTNode<int>*> q ; q.push(root) ; q.push(NULL) ;
    while(! q.empty()){
        BTNode<int>* f = q.front() ; q.pop() ;
        if(f == NULL) {
            v.push_back(temp) ; temp.clear() ;
            if(! q.empty()) q.push(NULL) ;
        }
        else {
            temp.push_back(f->data) ;
            if(f->left) q.push(f->left)   ;
            if(f->right) q.push(f->right) ;
        }
    }

    return v ;
}