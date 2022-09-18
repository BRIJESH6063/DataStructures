#include<bits/stdc++.h>
#include"BStree.cpp"
using namespace std ;

BSTNode<int>* takeInputLevelWise()
{
    int data ; cin >> data ;
    if(data == -1) return NULL ;
    BSTNode<int>* root = new BSTNode<int>(data) ;
    queue<BSTNode<int>*> q ;
    q.push(root) ;
    while(! q.empty()){
        BSTNode<int>* f = q.front() ;
        q.pop() ;

        int leftChild ; cin >> leftChild ;
        if(leftChild != -1) {
            BSTNode<int>* node1 = new BSTNode<int>(leftChild) ;
            q.push(node1) ; f->left = node1 ;
        }

        int rightChild ; cin >> rightChild ;
        if(rightChild != -1) {
            BSTNode<int>* node2 = new BSTNode<int>(rightChild) ;
            q.push(node2) ; f->right = node2 ;
        }

    }
    return root ;
}

BSTNode<int>* searchBST(BSTNode<int>* root, int val)
{
    // while(root){
    //     if(root->val == val) return root ;
    //     else if(root->val > val) root = root->left ;
    //     else root = root->right ;
    // }
    // return NULL ;
    if(! root) return NULL ;
    if(root->data == val) return root ;
    if(val < root->data) return searchBST(root->left, val) ;
    if(val > root->data) return searchBST(root->right, val) ;
    return NULL ;
}

// vector<vector<int>> levelOrder(BSTNode<int>* root)
// {
//     vector<vector<int>> v ; vector<int> temp ;
//     queue<BSTNode<int>*> q ; q.push(root) ; q.push(NULL) ;
//     while(! q.empty()){
//         BSTNode<int>* f = q.front() ; q.pop() ;
//         if(f == NULL) {
//             v.push_back(temp) ; temp.clear() ;
//             if(! q.empty()) q.push(NULL) ;
//         }
//         else {
//             temp.push_back(f->data) ;
//             if(f->left) q.push(f->left)   ;
//             if(f->right) q.push(f->right) ;
//         }
//     }
//     return v ;
// }

int findMin(BSTNode<int>* root)
{
    if(! root) return -1 ;
    while(root->left) root = root->left ;
    return root->data ;
}

int findMax(BSTNode<int>* root)
{
    if(! root) return -1 ;
    while(root->right) root = root->right ;
    return root->data ;
}

int rangeSumBST(BSTNode<int>* root, int L, int R) {
    if(! root) return 0 ;
    int sum = 0 ;
    if(root->data >= L && root->data <= R) sum += root->data ;
    if(root->data > R) sum += rangeSumBST(root->left, L, R) ;
    else if(root->data < L) sum += rangeSumBST(root->right, L, R) ;
    else sum +=  rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) ;   
    return sum ;
}

// bool isBST(BSTNode<int>* root, int prevData)
// {
//     if(root == NULL) return true ; 
//     if(root->left == NULL && rooot->right == NULL) return true ;
//     if(root->data > prevData) return false 
//     prevData = root->data ;
//     return (isBST(root->left, prevData) && isBST(root->right, prev) ;
// }

bool helper(BSTNode<int>* root, long long minV = -1*(1e10), long long maxV = (1e10)){
    if(! root) return true ;
    bool leftB = helper(root->left, minV, root->data) ;
    bool rightB = helper(root->right, root->data, maxV) ;
    if(leftB && rightB && (root->data > minV) && (root->data < maxV)) return true ;
    else return false ;
}
bool isValidBST(BSTNode<int>* root) {
    return helper(root) ;
}

BSTNode<int>* helper(vector<int> v, int start, int end){
    if(start > end) return NULL ;
    int mid = (start+end)/2 ;
    BSTNode<int>* root = new BSTNode<int>(v[mid]) ;
    root->left = helper(v, start, mid-1) ;
    root->right = helper(v, mid+1, end) ;

    return root ;
}

BSTNode<int>* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1) ;
}
