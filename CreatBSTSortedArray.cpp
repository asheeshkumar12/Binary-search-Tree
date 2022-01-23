BinaryTreeNode<int>* helper(int *in,int low,int high)
{
    if(low>high)
        return NULL;
    
        int mid=low+(high-low)/2;
        int rootData=in[mid];
        BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
        BinaryTreeNode<int>* leftsub=   helper(in,low,mid-1);
        BinaryTreeNode<int>* rightsub= helper(in,mid+1,high);
         root->left=leftsub;
        root->right=rightsub;
        return root;
    
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n==0)
        return NULL;
   /* if(n==1)
    {
        BinaryTreeNode<int>*root=new BinaryTreeNode<int>(input[0]);
        return root;
    }*/
   return  helper(input,0,n-1);
    
    
}
