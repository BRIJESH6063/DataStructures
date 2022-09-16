#include<bits/stdc++.h>
#include"BTree.cpp"
using namespace std ;

void printBTree(BTNode<int>* root) {
    if(! root) return ;
    if(root->left || root->right) cout << root->data << " : " ;
    if(root->left) cout << " left " << root->left->data << " : " ;
    if(root->right) cout << " right " << root->right->data << endl ;
    
    printBTree(root->left)  ;
    printBTree(root->right) ;
}


BTNode<int>* TakeInput(){
    int data ; cin >> data ;
    if(data == -1) return NULL ;
    BTNode<int>* root = new BTNode<int>(data) ;
    BTNode<int>* leftChild  = TakeInput() ;
    BTNode<int>* rightChild = TakeInput() ;

    root->left = leftChild ; root->right = rightChild ;
    return root ;
}

BTNode<int>* takeInputLevelWise()
{
    int data ; cin >> data ;
    if(data == -1) return NULL ;
    BTNode<int>* root = new BTNode<int>(data) ;
    queue<BTNode<int>*> q ;
    q.push(root) ;
    while(! q.empty()){
        BTNode<int>* f = q.front() ;
        q.pop() ;

        int leftChild ; cin >> leftChild ;
        if(leftChild != -1) {
            BTNode<int>* node1 = new BTNode<int>(leftChild) ;
            q.push(node1) ; f->left = node1 ;
        }
        // else f->left = NULL ;

        int rightChild ; cin >> rightChild ;
        if(rightChild != -1) {
            BTNode<int>* node2 = new BTNode<int>(rightChild) ;
            q.push(node2) ; f->right = node2 ;
        }
        // else f->right= NULL ;

    }
    return root ;
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

int countNodes(BTNode<int>* root)
{
    if(root == NULL) return 0 ;
    return countNodes(root->left) + countNodes(root->right) + 1 ;
}

void inorderTraversal(BTNode<int>* root){
    if(root == NULL) return ;
    inorderTraversal(root->left) ;
    cout << root->data << "  " ; 
    inorderTraversal(root->right) ;

}

void preorderTraversal(BTNode<int>* root){
    if(root == NULL) return ;
    cout << root->data << "  " ; 
    preorderTraversal(root->left) ;
    preorderTraversal(root->right) ;  
}

void postorderTraversal(BTNode<int>* root){
    if(root == NULL) return ;
    postorderTraversal(root->left) ;
    postorderTraversal(root->right) ; 
    cout << root->data << "  " ;  
}

int maxDepthBTree(BTNode<int>* root){
    if(root == NULL) return 0 ;
    return 1 + max(maxDepthBTree(root->left), maxDepthBTree(root->right)) ;
}

/*
   
   void preorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return ;
        ans.push_back(root->val) ;
        preorder(root->left, ans) ;
        preorder(root->right, ans) ;  
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans ;
        preorder(root, ans) ;
        
        return ans ;
    }

*/
bool helper(BTNode<int>* tree1, BTNode<int>* tree2)
{
    if(tree1 == NULL && tree2 != NULL) return false ;
    if(tree1 != NULL && tree2 == NULL) return false ;
    
    if(tree1 == NULL && tree2 == NULL) return true  ;
    if(tree1->data != tree2->data)     return false ;

    return (helper(tree1->left, tree2->right) && helper(tree1->right, tree2->left)) ;
}
bool isSymmetric(BTNode<int>* root)
{
    if(root == NULL) return true ;
    return helper(root->left, root->right) ;
}

bool searchNode(BTNode<int>* root, int key)
{
    if(root == NULL) return false ;
    if(root->data == key) return true ;
    else return (searchNode(root->left, key) || searchNode(root->right, key)) ;
}

int minValue(BTNode<int>* root){
    if(root == NULL) return INT_MAX ;
    return min(min(minValue(root->left), minValue(root->right)), root->data) ;
}

int maxValue(BTNode<int>* root){
    if(root == NULL) return INT_MIN ;
    return max(max(maxValue(root->left), maxValue(root->right)), root->data) ;
}

int countLeafNode(BTNode<int>* root){
    if(root == NULL) return 0 ;
    if(root->left == NULL && root->right == NULL) return 1 ;

    return (countLeafNode(root->left)+countLeafNode(root->right)) ;
}