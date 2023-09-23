/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach:
// Inorder works in order: left, node, right recursively 


class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root) {
        if (root == NULL) 
            return;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};