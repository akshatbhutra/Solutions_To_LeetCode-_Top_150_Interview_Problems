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

// https://leetcode.com/problems/palindrome-linked-list/
// Approach:
// get values of linked list & checkfor palindrome
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
    
    bool is_palin(vector<int> v) {
        int n = (int)(v.size());
        for (int i = 0; i < n / 2; i++) {
            if (v[i] != v[n - 1 - i])
                return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        return is_palin(get(head));
    }
};