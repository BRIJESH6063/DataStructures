#include<bits/stdc++.h>
#include"Tree.cpp"
using namespace std ;

TreeNode<int>* TakeInput(){
    int data ; cout << "Input data : " ; cin >> data ;
    TreeNode<int>* root = new TreeNode<int>(data)  ;
    int n ; cout << "Input no. of children of " << root->data << " : " ; cin >> n ;
    for(int i=0; i<n; i++) {
        TreeNode<int>* node = TakeInput() ;
        root->child.push_back(node) ;
    }

    return root ;
}

TreeNode<int>* TakeInputLevelWise(){
    int data ; cout << "Input root data : " ; cin >> data ;
    TreeNode<int>* root = new TreeNode<int>(data) ;
    queue<TreeNode<int>*> q ;
    q.push(root) ;

    while(!q.empty()){
        TreeNode<int>* f = q.front() ; q.pop() ; int n ;
        cout << "Input no. of children of " << f->data << " : " ; cin >> n ;
        if(n) cout << "Input the children datas of " << f->data << " : " ;
        for(int i=0; i<n; i++){
            int Cdata ; cin >> Cdata ;
            TreeNode<int>* node = new TreeNode<int>(Cdata) ;
            q.push(node) ; f->child.push_back(node) ;
        }
    }

    return root ;
}

// void PrintTree(TreeNode<int>* root)
// {
//     cout << root->data << "  " ;
//     for(TreeNode<int>* x : root->child) 
//     PrintTree(x) ;
//     // This print tree function doesnot mention the nodes and their children 
//     // not a good method of printing Tree.
// }

void PrintTree(TreeNode<int>* root)
{
    if(root == NULL) return ; // not a base case but it is to prevent null root 
    cout << root->data << " : " ;
    for(TreeNode<int>* x : root->child) 
    cout << x->data << " " ; cout << endl ;
    for(TreeNode<int>* x : root->child) 
    PrintTree(x) ;

}

void PrintTreeLevelWise(TreeNode<int>* root)
{
    queue<TreeNode<int>*> q ; q.push(root) ;
    while(!q.empty()){
        TreeNode<int>* f = q.front() ; q.pop() ;
        if(f->child.size() == 0) continue ;
        cout << f->data << " : "  ;
        for(auto x : f->child){
            cout << x->data << " " ;
            q.push(x) ;
        }
        cout << endl ;
    }
}
