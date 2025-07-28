/*
A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
public:
   bool isUnivalTree(TreeNode* root){
     if(!root) return false;
     if(root->left){
        if(root->left->val!=root->val || !isUnivalTree(root->left)){
            return false;
        }
     }
     if(root->right){
        if(root->right->val!=root->val || !isUnivalTree(root->right)){
            return false;
        }
     }
     return true;
   }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;

    bool ans=sol.isUnivalTree(root);

    cout<<ans<<endl;
    
    return 0;
}