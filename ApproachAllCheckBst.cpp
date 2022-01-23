#include<iostream>
#include "binaryTreeNodeClass.cpp"
using namespace std;
#include<queue>
// take input level wise
BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}
// end input level wise

//print tree
void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}
// Approach 1

int minimum5(BinaryTreeNode<int>* root)
{

    if(root==NULL)
    {
         return INT_MAX;
    }

    return min(root->data,min(minimum5(root->left),minimum5(root->right)));
}
int maximum5(BinaryTreeNode<int> * root)
{

    if(root==NULL)
       return INT_MIN;
    return max(root->data,max(maximum5(root->left),maximum5(root->right)));
}
bool isBST7(BinaryTreeNode<int> * root)
{

    if(root==nullptr)
        return true;
    int leftMax=maximum5(root->left);
    int rightMin=minimum5(root->right);
    return (root->data >leftMax && root->data <=rightMin) && isBST7(root->left)&&isBST7(root->right);
}


//better approach 2 of check bst

// create a class return min ,max,isBST
class isBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root)
{

    if(root==nullptr)
    {
        isBSTReturn output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    isBSTReturn leftOutput=isBST2(root->left);
    isBSTReturn rightOutput=isBST2(root->right);
    int minimum3=min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum3=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal=(root->data >leftOutput.maximum  && root->data <=rightOutput.minimum)&& leftOutput.isBST
                       &&rightOutput.isBST;
    isBSTReturn output;
    output.maximum=maximum3;
    output.minimum=minimum3;
    output.isBST=isBSTFinal;
    return output;
}

//Approach 3

bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX)
{

    if(root==nullptr)
        return true;
    if(root->data <min|| root->data >max)
        return false;
    bool leftisOk=isBST3(root->left,min,root->data-1);
    bool rightisOk=isBST3(root->right,root->data,max);
    return leftisOk&&rightisOk;
}
//  8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main()
{

    BinaryTreeNode<int>* root=takeInputLevelWise();

      printTree(root);
      cout<<"Approach 1: ";
      cout<<isBST7(root)<<endl;

      isBSTReturn f=isBST2(root);
      cout<<"Approach 2 : "<<f.isBST<<endl;

      cout<<"Approach 3 : "<<isBST3(root)<<endl;

}
