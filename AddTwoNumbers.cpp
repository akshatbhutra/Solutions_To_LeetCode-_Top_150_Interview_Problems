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

// https://leetcode.com/problems/add-two-numbers/
// approach:
// get values from linked lists and process

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1 = get(l1);
        vector<int> v2 = get(l2);
        string s1, s2;
        for (auto e: v1) s1 += to_string(e);
        for (auto e: v2) s2 += to_string(e);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ss;
        int n1 = s1.size(), n2 = s2.size();
        if (n1 < n2) {
            while(1) {
                if (s1.size() == s2.size()) break;
                s1 = "0" + s1;
            }
        }
        else {
               while(1) {
                if (s1.size() == s2.size()) break;
                s2 = "0" + s2;
            }
        }
        int m = s1.size();
        int carry = 0;
        for (int i = m - 1; i >= 0; i--) {
            int d1 = s1[i] - '0';
            int d2 = s2[i] - '0';
            int sum = d1 + d2 + carry;
            carry = 0;
            if (sum <= 9) ss = to_string(sum) + ss;
            else {
                ss = to_string(sum % 10) + ss;
                carry = sum / 10;
            }
        }
        if(carry) ss = to_string(carry) + ss;
        reverse(ss.begin(), ss.end());
        vector<int> f;
        for (int i = 0; i < ss.size(); i++) 
            f.push_back((ss[i] - '0'));
        return make(f);
    }
};