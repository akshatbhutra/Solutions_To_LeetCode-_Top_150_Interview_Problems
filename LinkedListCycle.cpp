/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach1:
// check if it is visiting a node again

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* cur = head;
//         bool ok = 0;
//         set<ListNode*> vis;
//         bool repeating = 0;
//         while (1) {
//             repeating = vis.find(cur) != vis.end();
//             if (cur == NULL || repeating) {
//                 break;
//             }
//             vis.insert(cur);
//             cur = cur->next;      
//         }
//         return (repeating ? true : false);
//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach:
// slow and fast pointer approach
// Tortoise and Hare (Floyd's Cycle Detection) Algorithm

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode *fast = head;
        ListNode *slow = head;
    
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        return false;
    }
};