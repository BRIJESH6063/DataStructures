#include<bits/stdc++.h>
using namespace std ;

template<typename T>
class BSTNode {
    public :
            T data ;
            BSTNode<T> * left ; 
            BSTNode<T> * right ; 
            BSTNode(T data){
                this->data = data ;
                left = right = NULL ;
            }
            ~BSTNode(){
                delete left ; delete right ;
            }
} ;
class Pair {
    public :
        BSTNode<int>* head ;
        BSTNode<int>* tail ;
} ;

// implementation part .. // 
class BST {
    private :
            BSTNode<int>* root ;
            vector<vector<int>> levelOrder(BSTNode<int>* root)
            {
                vector<vector<int>> v ; vector<int> temp ;
                queue<BSTNode<int>*> q ; q.push(root) ; q.push(NULL) ;
                while(! q.empty()){
                    BSTNode<int>* f = q.front() ; q.pop() ;
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
            bool hasDataNode(BSTNode<int>* node, int data){
                if(! node) return false ; // bool ans1 ; bool ans2 ;
                if(node->data == data) return true ;
                if(node->data >  data) return hasDataNode(node->left, data) ;
                if(node->data <  data) return hasDataNode(node->right, data) ;
                // return (ans1 || ans2) ;
            }
            BSTNode<int>* insertNode(BSTNode<int>* node, int data){
                if(! node){
                    node = new BSTNode<int>(data) ; return node ;
                }
                if(data < node->data) node->left  = insertNode(node->left, data) ;
                if(data > node->data) node->right = insertNode(node->right, data) ;

                return node ;
            }
            BSTNode<int>* deleteDataNode(BSTNode<int>* root, int data){
                if(! root) return NULL ;
                if(data > root->data) {
                    root->right = deleteDataNode(root->right, data) ;
                }
                else if(data < root->data) {
                    root->left = deleteDataNode(root->left, data) ;
                }
                else {
                    if(root->left == NULL && root->right == NULL) {  // Case 1
                        delete root ; return NULL ;
                    }
                    else if(root->right == NULL){
                        BSTNode<int>* temp = root->left ; delete root ;
                        return temp ;
                    }
                    else if(root->left == NULL){
                        BSTNode<int>* temp = root->right ; delete root ;
                        return temp ;
                    }
                    else {
                        BSTNode<int>* minNode = root->right ;
                        if(root->right != NULL){
                            while(minNode->left != NULL){
                                minNode = minNode->left ;
                            }
                            int rightMinData = minNode->data ;
                            root->data  = rightMinData ;
                            root->right = deleteDataNode(root->right, rightMinData) ;
                        }
                        else {
                            minNode = root->left ;
                            while(minNode->right != NULL){
                                minNode = minNode->right ;
                            }
                            int leftMaxData = minNode->data ;
                            root->data  = leftMaxData ;
                            root->left = deleteDataNode(root->left, leftMaxData) ;
                        }
                    }
                }
                return root ;
            }
            Pair convertToLL(BSTNode<int>* root){
                if(root == NULL){
                    Pair ans ; ans.head = NULL ;
                    ans.tail = NULL ;
                    return ans ;
                }
                if(root->left == NULL && root->right == NULL){
                    Pair p ;
                    p.head = root ; p.tail = root ;
                    return p ;
                }
                else if(root->left != NULL && root->right == NULL){
                    Pair leftLL = convertToLL(root->left) ;
                    leftLL.tail->right = root ;
                    Pair ans ; ans.head = leftLL.head ; ans.tail = root ;
                    return ans ;
                }
                else if(root->left == NULL && root->right != NULL){
                    Pair rightLL = convertToLL(root->right) ;
                    root->right = rightLL.head ;
                    Pair ans ; ans.head = root ; ans.tail = rightLL.tail ;
                    return ans ;
                }
                else {
                    Pair leftLL  = convertToLL(root->left)  ;
                    Pair rightLL = convertToLL(root->right) ;
                    leftLL.tail->right = root ;
                    root->right = rightLL.head ;
                    Pair ans ; ans.head = leftLL.head ; ans.tail = rightLL.tail ;
                    return ans ;
                }

            }
    public :
            BST(){
                root = NULL ;
            }
            ~BST(){
                delete root ;
            }
            void deleteData(int data){
                root = deleteDataNode(root, data) ;
            }
            void insert(int data) {
                root = insertNode(root, data) ;
            }
            bool hasData(int data){
                return hasDataNode(root, data) ;
            }
            void printTree(){
                vector<vector<int>> v = levelOrder(root) ;
                for(auto x : v){
                    for(auto y : x) cout << y << " " ;
                    cout << endl ;
                }
            }
            BSTNode<int>* convertToLL(){
                Pair p = convertToLL(root) ;
                return p.head ;
            }
} ;

