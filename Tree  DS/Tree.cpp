#include<bits/stdc++.h>
using namespace std ;

template<typename T>
class TreeNode {
    public :
            T data ;
            vector<TreeNode<T>*> child ;
            TreeNode (T data){
                this->data = data ;
            }
} ;