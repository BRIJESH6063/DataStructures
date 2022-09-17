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


BTNode<int>* buildTreeHelper2(vector<int> inorder, vector<int> postorder, int inS, int inE, int posS, int posE)
{
    if(inS > inE) return NULL ;
    int data = postorder[posE] ;

    int LeftInS = inS ;
    int rootIndex = -1 ;
    for(int i=0; i<inorder.size(); i++){
        if(inorder[i] == data) rootIndex = i ;
    }
    int LeftInE  = rootIndex - 1; 
    int LeftPosS = posS ; 
    // leftInE - leftInS = leftPreE - leftPreS 
    int LeftPosE = LeftPosS + LeftInE - LeftInS ; 

    int RightInS  = rootIndex + 1 ; 
    int RightInE  = inE; 
    int RightPosS = LeftPosE + 1 ; 
    int RightPosE = posE - 1 ; 

    BTNode<int>* root = new BTNode<int>(data) ;
    root->left  = buildTreeHelper2(inorder, postorder, LeftInS, LeftInE, LeftPosS, LeftPosE) ;
    root->right = buildTreeHelper2(inorder, postorder, RightInS, RightInE, RightPosS, RightPosE) ;

    return root ;
}
BTNode<int>* buildTree2(vector<int> inorder, vector<int> postorder)
{
    int n = inorder.size() ;
    return buildTreeHelper2(inorder, postorder, 0, n-1, 0, n-1) ;
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

int height(BTNode<int>* root){
    if(root == NULL) return 0 ;
    return 1 + max(height(root->left), height(root->right)) ;
}

int diameterTree(BTNode<int>* root){
    if(! root) return 0 ;
    int option1 = height(root->left) + height(root->right) ;
    int option2 = diameterTree(root->left) ;
    int option3 = diameterTree(root->right) ;

    return max(option1, max(option2, option3)) ;
}

pair<int, int> heightDiameter(BTNode<int>* root)
{
    if(root == NULL){
        pair<int, int> p = make_pair(0,0) ;
        return p ;
    }

    pair<int, int> leftAns = heightDiameter(root->left) ;
    pair<int, int> rightAns = heightDiameter(root->right) ;

    int lh = leftAns.first ; int ld = leftAns.second ;
    int rh = rightAns.first ; int rd = rightAns.second ;

    int height = 1 + max(lh, rh) ;
    int diameter = max(lh+rh, max(ld, rd)) ;

    return make_pair(height, diameter) ;
}
pair<int, int> diameterOptimised(BTNode<int>* root){
    pair<int, int> p = heightDiameter(root) ;
    return p ;
}

bool getPath(BTNode<int>* root, int n, vector<int> &v){
    if(root == NULL) return false ;
    v.push_back(root->data) ;
    if(root->data == n) return true ;

    bool leftPath = getPath(root->left, n, v) ;
    bool rightPath = getPath(root->right, n, v) ;

    if(leftPath || rightPath) return true ;
    v.pop_back() ; return false ;

}