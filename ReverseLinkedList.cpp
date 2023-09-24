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

// https://leetcode.com/problems/reverse-linked-list/
// approach:
// get original values, reverse values and create new linked list

class Solution {
public:
    ListNode* make(vector<int> v) {
        int n = v.size();
        ListNode* root = new ListNode(v[0]), *prev = root;
        for (int i = 1; i < n; i++) {
            ListNode* cur = new ListNode(v[i]);
            prev->next = cur;
            prev = cur;
        }
        return root;
    }

    vector<int> get(ListNode* r) {
        vector<int> v;
        while(r != NULL) {
            v.push_back(r->val);
            r = r->next;
        }
        return v;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> v = get(head);
        int n = (int)(v.size());
        for (int i = 0; i < n / 2; i++) {
            swap(v[i], v[n - 1 - i]);
        }
        return make(v);
    }
};