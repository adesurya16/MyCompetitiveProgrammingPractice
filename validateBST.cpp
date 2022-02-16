#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBST(TreeNode* root, int leftMin, int rightMax){
    if (root == nullptr) return true;
    else if(leftMin >= root -> val || rightMax <= root -> val){
        return false;
    }
    return isBST(root->left, leftMin, root->val) && isBST(root->right, root->val, rightMax);
}

bool isValidBST(TreeNode* root){
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << isValidBST(root) << endl;
    return 0;
}