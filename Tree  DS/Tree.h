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

int countNodes(TreeNode<int>* root)
{
    int ans = 1 ;
    for(auto x : root->child){
        ans += countNodes(x) ;
    }
    return ans ;
}

int height(TreeNode<int>* root)
{
    int maxH = 0 ;  // storing the maximum height at any level.
    for(auto x : root->child){
        int childHeight = height(x) ;
        maxH = max(maxH, childHeight) ;
    }
    return maxH + 1 ;
}

void printAtLevelk(TreeNode<int>* root, int k){
    if(! root) return ;
    if(k == 0) {
        cout << root->data << " " ;
        return ;
    }
    for(auto x : root->child){
        printAtLevelk(x, k-1) ;
    }
}

int countLeafNodes(TreeNode<int>* root){
    if(! root) return 0 ;
    if(root->child.size() == 0) return  1 ;
    int ans = 0 ;
    for(auto x : root->child){
        ans += countLeafNodes(x) ;
    }
    return ans ;
}

void PreOrderTraversal(TreeNode<int>* root){
    if(! root) return ;  // edge case not base case.
    cout << root->data << "  " ;
    for(auto x : root->child){
        PreOrderTraversal(x) ;
    }
}

void PostOrderTraversal(TreeNode<int>* root){
    if(! root) return ;
    for(auto x : root->child){
        PreOrderTraversal(x) ;
    }
    cout << root->data << "  " ;
}

void deleteTree(TreeNode<int>* root){
    if(! root) return ;
    for(int i=0; i<root->child.size(); i++){
        deleteTree(root->child[i]) ;
    }
    delete root ; root = NULL ;
}