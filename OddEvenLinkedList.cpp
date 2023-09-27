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
// [odd nodes]->[even nodes]
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
			return NULL;
        ListNode* odd_node, *even_node, *evenhead;
		odd_node = head;
		even_node = head->next;
		evenhead = head->next;

		while (even_node != NULL and even_node->next != NULL) {
			odd_node->next = odd_node->next->next;
			even_node->next = even_node->next->next;

			odd_node = odd_node->next;
			even_node = even_node->next;
        }

		odd_node->next = evenhead;
            

		return head;
    }
};