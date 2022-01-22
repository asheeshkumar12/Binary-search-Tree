bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root==NULL)
        return false;
    if(root->data==k)
        return true;
    else if(root->data > k)
        searchInBST(root->left,k);
    else
        searchInBST(root->right,k);
    
}
