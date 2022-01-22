#include<bits/stdc++.h>
bool isBSTUntill(BinaryTreeNode<int>* root,int min,int max)
 {
     if(root==NULL)
     {
         return 1;
     }
     if(root->data < min || root->data >max)
     {
         return 0;
     }
     return isBSTUntill(root->left,min,root->data-1) 
         && isBSTUntill(root->right,root->data+1,max);
 }
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    return isBSTUntill(root,INT_MIN,INT_MAX);
}
