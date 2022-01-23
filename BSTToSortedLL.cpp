

#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

















pair<Node<int>*,Node<int>* >  help(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>* > p;
        p.first=NULL;
        p.second=NULL;
        return p;
        
    }
    if(root->left == NULL && root->right ==NULL)
    {
        pair<Node<int>*,Node<int>*> p;
        Node<int>* head = new Node<int>(root->data);
        Node<int>* tail = head;
        p.first = head;
        p.second = tail;
        return p;
    }
    pair<Node<int>*,Node<int>* > pL=help(root->left);
    pair<Node<int>*,Node<int>* > pR=help(root->right);
    Node<int>* temp=new Node<int>(root->data);
         pair<Node<int>*,Node<int>* > pans;
    if(pL.first==NULL )
    {
        
        temp->next = pR.first;
        pans.first = temp;
        pans.second = pR.second;
        return pans;
        
    }
    if(pR.first==NULL)
    {
        pL.second->next = temp;
        pans.first = pL.first;
        pans.second = temp;
        return pans;
    }


    pans.first=pL.first;
        pL.second->next=temp;
        temp->next=pR.first;
    

    
    pans.second=pR.second;
    return pans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    pair<Node<int>*,Node<int>*> p;
    p=help(root);
    return p.first;
}
