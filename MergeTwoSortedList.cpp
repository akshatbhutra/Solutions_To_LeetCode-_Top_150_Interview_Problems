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

// Recursive Solution

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if (list1 == NULL)
//             return list2;
//         if (list2 == NULL)
//             return list1;
//         if (list1->val < list2->val)  {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else  {
//             list2->next = mergeTwoLists(list2->next, list1);
//             return list2;
//         }
//     }
// };

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

// Iterative Solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode* root;
        if (list1->val < list2->val) {
            root = list1;
            list1 = list1->next;
        }
        else {
            root = list2;
            list2 = list2->next;
        }
        ListNode* cur = root;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur -> next;
        }
        if (list1 == NULL) {
            cur->next = list2; 
        }
        else if (list2 == NULL) {
            cur->next = list1;
        }
        return root;
    }
};