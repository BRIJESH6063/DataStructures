#include<bits/stdc++.h>
#include"Tree.h"
using namespace std ;


int main()
{
    // TreeNode<int>* root = TakeInput() ;
    TreeNode<int>* root = TakeInputLevelWise() ;

    // TreeNode<int>* root  = new TreeNode<int>(22) ;
    // TreeNode<int>* node1 = new TreeNode<int>(28) ;
    // TreeNode<int>* node2 = new TreeNode<int>(75) ;
    // TreeNode<int>* node3 = new TreeNode<int>(36) ;
    // TreeNode<int>* node4 = new TreeNode<int>(77) ;
    // TreeNode<int>* node5 = new TreeNode<int>(49) ;

    // root->child.push_back(node1)  ;
    // root->child.push_back(node2)  ;
    // root->child.push_back(node3)  ;
    // node2->child.push_back(node4) ;
    // node3->child.push_back(node5) ;

    // PrintTree(root) ;
    PrintTreeLevelWise(root) ;
    return 0 ;
}