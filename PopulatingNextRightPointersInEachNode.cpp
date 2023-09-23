/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Approach:
// do level order traversal and link next as said.

class Solution {
public:
    vector<Node*> call(vector<Node*> initial_pointers) {
        vector<Node*> final_pointers;
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
    
    Node* levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<Node*> cur;
        if (root != NULL) {
            cur.push_back(root);
        }
        while (1) {
            vector<Node*> pointers = call(cur);
            if(pointers.empty())
                break;
            for (int i = 0; i < (int)(pointers.size()) - 1; i++) {
                pointers[i]->next = pointers[i + 1]; 
            }
            cur = pointers;
        }
        return root;
    }
    
    Node* connect(Node* root) {
        return levelOrder(root);
    }
};