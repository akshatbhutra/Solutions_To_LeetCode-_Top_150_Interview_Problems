// Approach:
// Simply manintain "carry" to be accumulated while iterating from lowest significant digit to most significant one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = (int)(digits.size());
        bool carry = 0;
        if (digits[n - 1] == 9)
                carry = 1;
        digits[n - 1]++;
        ans.push_back(digits[n - 1] % 10);
        int i = -2;
        for (i = n - 2; i >= 0; i--) {
            if (!carry) {
                ans.push_back(digits[i]);
                continue;
            }
            if (digits[i] != 9) {
                digits[i]++;
                carry = 0;
            }
            else {
                digits[i] = 0;
            }
            ans.push_back(digits[i]);
        }
        if (carry) 
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};