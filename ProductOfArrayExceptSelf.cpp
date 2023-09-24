// https://leetcode.com/problems/product-of-array-except-self/
// approach:
// product[i] = pre[i - 1] * suff[i + 1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)(nums.size());
        vector<int> ans(n, 1);
        int p[n], s[n];
        p[0] = nums[0];
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * nums[i];
        }
        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s[i] = s[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (i > 0)
                ans[i] = p[i - 1];
            if (i + 1 < n)
                ans[i] *= s[i + 1];
        }
        return ans;
    }
};