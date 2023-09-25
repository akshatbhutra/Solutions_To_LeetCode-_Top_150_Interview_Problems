/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// approach:
// O(1) space solution
// After intersection both linked lists will have same size
// before intersection their sizes may differ
// find the difference "diff"
// then move head pointer in larger list "diff" steps ahead
// now both linked lists are of same size (counting from their head)\
// now check for intersection


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
    
    
    int getSize(ListNode* r) {
        int ans = 0;
        while(r != NULL) {
            ans++;
            r = r->next;
        }
        return ans;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getSize(headA), l2 = getSize(headB);
        ListNode* origheadA = headA, *origheadB = headB, *ans;
        
        int diff = abs(l1 - l2);
        if (l1 > l2) {
            for (int i = 0; i < diff; i++)
                headA = headA->next;
        }
        else {
            for (int i = 0; i < diff; i++)
                headB = headB->next;
        }
        while(1) {
            if (headA == NULL)
                break;
            if (headA == headB) {
                ans = headA;
                headA = origheadA;
                headB = origheadB;
                return ans;
            }
            headA = headA->next;
            headB = headB->next;
        }
        headA = origheadA;
        headB = origheadB;
        return NULL;
    }
};