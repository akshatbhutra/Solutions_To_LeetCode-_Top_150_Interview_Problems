/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach:
// When we delete a node just connect its previous to its next.
// Corner case: deletion of root itself as it dont have any previous
class Solution {
public:
    vector<int> get(ListNode* r) {
        vector<int> v;
        while(r != NULL) {
            v.push_back(r->val);
            r = r->next;
        }
        return v;
    }
    ListNode* remove(ListNode* head, int position) {
        if (position == 1) {
            ListNode* root = head->next;
            delete head;
            return root;
        }
        ListNode *cur = head, *prev = NULL, *nextnode;
        for (int i = 0; i < position - 1; i++) {
            prev = cur;
            cur = cur->next;
        }
        nextnode = cur->next;
        if (prev != NULL)
            prev->next = nextnode;
        delete cur;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return remove(head, (int)(get(head).size()) - n + 1);
    }
};