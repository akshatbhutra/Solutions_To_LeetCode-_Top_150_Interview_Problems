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
// Two pointer Approach: Maintain two pointers and iterate over the two lists.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2, *ans = NULL, *prev, *newnode;
        while (cur1 != NULL || cur2 != NULL) {
            if (cur1 != NULL && cur2 != NULL) {
                if (ans == NULL) {
                    if (cur1->val < cur2->val) {
                        ans = new ListNode(cur1->val);
                        cur1 = cur1->next;
                    }
                    else {
                        ans = new ListNode(cur2->val);
                        cur2 = cur2->next;
                    }
                    prev = ans;
                }
                else {
                    if (cur1->val < cur2->val) {
                        newnode = new ListNode(cur1->val);
                        prev->next = newnode;
                        cur1 = cur1->next;
                        prev = newnode;
                    }
                    else {
                        newnode = new ListNode(cur2->val);
                        prev->next = newnode;
                        cur2 = cur2->next;
                        prev = newnode;
                    }
                }  
            }
            else if (cur1 == NULL) {
                    if (ans == NULL) {
                        ans = new ListNode(cur2->val);
                        cur2 = cur2->next;
                        prev = ans;
                    }
                    else {
                            newnode = new ListNode(cur2->val);
                            prev->next = newnode;
                            cur2 = cur2->next;
                            prev = newnode;
                    }
            }
            else if (cur2 == NULL) {
                    if (ans == NULL) {
                            ans = new ListNode(cur1->val);
                            cur1 = cur1->next;
                            prev = ans;
                    }
                    else {
                            newnode = new ListNode(cur1->val);
                            prev->next = newnode;
                            cur1 = cur1->next;
                            prev = newnode;
                    }
            }
        }
        return ans;
    }
};