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
// reverse in place

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* cur = head, *prev = NULL, *forward;
        while (1) {
            if (cur == NULL)
                break;
            forward = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forward;
        }
        return prev;
    }
};