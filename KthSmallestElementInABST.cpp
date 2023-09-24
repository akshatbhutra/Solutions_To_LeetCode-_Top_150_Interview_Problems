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

// approach:
// inorder traversal of BST gives ascending order of values

class Solution {
public:
    vector<int> inorder_values;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        inorder_values.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return inorder_values[k - 1];
    }
};