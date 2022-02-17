

// allready a given bst that in insert a node a specific position 

Node * insert(Node * root, int data)
{
  if(root==nullptr)
  {
    Node *f=new Node(data);
    return f;
  }
  if(root->data < data)
  {
    root->right=insetr(root->right,data);
  }
  if(root->data > data){
   root->left=insert(root->left,data); 
    
  }
  
  return root;
  
}
