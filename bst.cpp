// problem to convert common BST (Binary Search Tree) to Balanced BST

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// inorder traversal a BST (result store to vector/list, this vector/list must be sorted)
void storeBSTnodes(node* root, vector<node*> &nodes){
    if (root != NULL){
        storeBSTnodes(root->left, nodes);
        nodes.push_back(root);
        storeBSTnodes(root->right, nodes);
        // root->left == NULL; // not need handle, handle on basis rekursif when build balanced BST
        // root->right == NULL;
    }
}

// build balanced BST minimum height/level a BST
node* buildBSTBalanced(vector<node*> &nodes, int left, int right){
    if (left > right) return NULL; // sisa child left/right di handle disini
    
    int mid = (left + right) / 2;
    // get the middle value for root and get balanced 
    node* root = nodes[mid];
    root->left = buildBSTBalanced(nodes, left, mid - 1);
    root->right = buildBSTBalanced(nodes, mid + 1, right);
    return root;
}

/* Function to do preorder traversal of tree */
void preOrder(node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

node* newNode(int data)
{
    node* root = new node;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

node* buildTree(node* root)
{
    // root is a unbalanced BST
    // Store nodes of given BST in sorted order
    vector<node*> nodes;
    storeBSTnodes(root, nodes);
 
    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildBSTBalanced(nodes, 0, n-1);
}

int main (){
    node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
    root->left->left->left->left->left = newNode(3);

    node* root2 = newNode(5);
    root2->right = newNode(6);
    root2->right->right = newNode(7);
    root2->right->right->right = newNode(8);
    root2->right->right->right->right = newNode(10);
    root2->right->right->right->right->right = newNode(11);

    root = buildTree(root);
    preOrder(root);
    cout << endl;
    root2 = buildTree(root2);
    preOrder(root2);
    cout << endl;
    return 0;
}