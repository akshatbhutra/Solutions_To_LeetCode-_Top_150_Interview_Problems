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

// Approach1:
// DFS and passing depth as parameter

// class Solution {
// public:
//     int m = 0;
//     void dfs(TreeNode* u, int d) {
//         m = max(m, d);
//         if (u->left != NULL)
//             dfs(u->left, d + 1);
//         if (u->right != NULL)
//             dfs(u->right, d + 1);
//     }
//     int maxDepth(TreeNode* root) {
//         if (root != NULL)
//             dfs(root, 1);
//         return m;
//     }
// };



// Approach2:
// recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};