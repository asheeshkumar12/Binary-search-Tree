/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
        root=nullptr;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
    
     bool search(int data,BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data==data)
        {
            return true;
        }
        else if(root->data > data)
        {
            search(data,root->left);
        }
        else
        {
            
        search(data,root->right);    
        }
        
    }
    
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
         BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(data);
         return temp;
        }
        
        if(data > root->data)
        {
            root->right=insert(data,root->right);
        }
        else
        {
            root->left=insert(data,root->left);
        }
        
    }
    // delet enode
     BinaryTreeNode<int>* remove(int data,BinaryTreeNode<int>* root)
   {
       if(root==NULL)
       {
           return NULL;
       }
       if(data < root->data)
       {
           root->left=remove(data,root->left);

       }
       else if(data > root->data)
       {
           root->right=remove(data,root->right);
       }
       else
       {
           if(root->left==NULL && root->right==NULL)
           {
               delete root;
               return NULL;
           }
           else if(root->left==NULL)
           {
               BinaryTreeNode<int>* temp=root->right;
               root->right=NULL;
               delete root;
               return temp;
           }
           else if(root->right==NULL)
           {
               BinaryTreeNode<int>* temp=root->left;
               root->left=NULL;
               delete root;
               return temp;
           }
           else
           {
               BinaryTreeNode<int>* minNode=root->right;
               while(minNode->left!=nullptr)
               {
                   minNode=minNode->left;
               }
               int rightMin=minNode->data;
               root->data=rightMin;
               root->right=remove(rightMin,root->right);
           }
       }
   }
    
    //  print Tree 
    void print(BinaryTreeNode<int>* root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<":";
    if(root->left!=nullptr)
    {
        cout<<"L:"<<root->left->data<<",";
    }
    if(root->right!=nullptr)
    {
        cout<<"R:"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);

}
    public:
    
    void remove(int data) { 
        // Implement the remove() function 
        root=remove(data,root);
    }

    void print() { 
        // Implement the print() function
        print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
         this->root=insert(data,this->root);
    }

    bool search(int data) {
		// Implement the search() function 
        return search(data,this->root);
    }
};

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include "solution.h"

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
