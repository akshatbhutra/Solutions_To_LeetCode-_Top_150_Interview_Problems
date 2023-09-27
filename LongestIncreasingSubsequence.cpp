// https://leetcode.com/problems/longest-increasing-subsequence/
// Approach:
// dp[i] = longest strictly increasing subsequence ending at i.
// dp[i] = max(dp[j] + 1) for j < i 
// O(n*n) approach

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)(nums.size());
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};