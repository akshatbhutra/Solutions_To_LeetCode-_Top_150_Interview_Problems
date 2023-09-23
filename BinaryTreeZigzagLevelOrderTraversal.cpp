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

// Approach:
// Simple level order traversal but reverse order based on level parity

class Solution {
public:
    vector<TreeNode*> call(vector<TreeNode*> initial_pointers) {
        vector<TreeNode*> final_pointers;
        for (auto &e: initial_pointers) {
            if (e != NULL) {
                if (e->left != NULL) {
                    final_pointers.push_back(e->left);
                }
                if (e->right != NULL) {
                    final_pointers.push_back(e->right);
                }
            }
        }
        return final_pointers;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> cur;
        cur.push_back(root);
        if (root != NULL)
            ans.push_back({root->val});
        int level = 1;
        while (1) {
            vector<TreeNode*> pointers = call(cur);
            vector<int> values;
            for (auto &e: pointers)
                values.push_back(e->val);
            cur = pointers;
            if(cur.empty())
                break;
            if (level & 1)
                reverse(values.begin(), values.end());
            ans.push_back(values);
            level++;
        }
        return ans;
    }
    
};