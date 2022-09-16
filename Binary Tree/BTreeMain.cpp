#include<bits/stdc++.h>
#include"BTree.h"
using namespace std ;

int main()
{
    // BTNode<int>* root  = new BTNode<int>(22) ;
    // BTNode<int>* node1 = new BTNode<int>(48) ;
    // BTNode<int>* node2 = new BTNode<int>(71) ;
    // BTNode<int>* node3 = new BTNode<int>(55) ;
    // BTNode<int>* node4 = new BTNode<int>(93) ;

    // root->left = node1 ; root->right = node2   ;
    // node1->left = node3 ; node1->right = node4 ;
    // BTNode<int>* root = TakeInput() ;

    BTNode<int>* root = takeInputLevelWise() ;
    printBTree(root) ;

    vector<vector<int>> ans = levelOrder(root) ;
    for(auto x : ans){
        for(auto y : x) cout << y << "  " ;
        cout << endl ;
    }
    cout << "Number of nodes in tree : " <<  countNodes(root) << endl ;
    cout << "Inorder  Traversal  : " ; inorderTraversal(root)   ; cout << endl ;
    cout << "Preorder Traversal  : " ; preorderTraversal(root)  ; cout << endl ;
    cout << "Postorder Traversal : " ; postorderTraversal(root) ; cout << endl ;
    cout << "Max depth of Tree   : " << maxDepthBTree(root) << endl ;

    if(isSymmetric(root)) cout << "The Tree is Symmetric." << endl ;
    else cout << "The Tree is not Symmetric." << endl ;
    if(searchNode(root, 2)) cout << "The Tree contains 2." << endl ;
    else cout << "The Tree does not contain 2." << endl ;

    cout << "Minimum value contained in tree : " << minValue(root) << endl ;
    cout << "Maximum value contained in tree : " << maxValue(root) << endl ;
    cout << "Leaf nodes count of the tree    : " << countLeafNode(root) << endl ;

    delete root ;
    return 0 ;

}

/* Input --
   1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
   5 2 2 6 8 8 6 -1 -1 -1 -1 -1 -1 -1 -1
  
  */