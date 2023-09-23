/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach:
// check if it is visiting a node again

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        bool ok = 0;
        set<ListNode*> vis;
        bool repeating = 0;
        while (1) {
            repeating = vis.find(cur) != vis.end();
            if (cur == NULL || repeating) {
                break;
            }
            vis.insert(cur);
            cur = cur->next;      
        }
        return (repeating ? true : false);
    }
};