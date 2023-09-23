/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// approach:
// generate two lists of pointers and see their intersection
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

    vector<ListNode*> get(ListNode* r) {
        vector<ListNode*> v;
        while(r != NULL) {
            v.push_back(r);
            r = r->next;
        }
        return v;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> vis;
        for (auto &e: get(headA))
            vis[e] = 1;
        for (auto &e: get(headB))
            if(vis[e])
                return e;
        return NULL;
    }
};