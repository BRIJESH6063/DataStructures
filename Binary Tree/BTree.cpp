#include<bits/stdc++.h>
using namespace std ;

template<typename T>
class BTNode {
    public :
           T data ;
           BTNode* left ; BTNode* right ;
           BTNode(T data){
            this-> data = data  ;
            left = right = NULL ;
           }
           ~BTNode(){
            delete left ; delete right ;
           }
} ;