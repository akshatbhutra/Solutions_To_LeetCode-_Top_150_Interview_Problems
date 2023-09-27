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

// approach
// O(N) space solution

class Solution {
public:
    ListNode* make(vector<int> v) {
        int n = v.size();
        if (n == 0)
            return NULL;
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
    
    ListNode* oddEvenList(ListNode* head) {
        vector<int> v =  get(head), vv;
        int n = (int)(v.size());
        for (int i = 0; i < n; i += 2) {
            vv.push_back(v[i]);   
        }
        for (int i = 1; i < n; i += 2) {
            vv.push_back(v[i]);   
        }
        return make(vv);
    }
};