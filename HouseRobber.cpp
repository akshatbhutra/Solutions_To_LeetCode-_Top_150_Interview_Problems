// https://leetcode.com/problems/house-robber/
// approach:
//  dp[i][0] = ans till initial i values if ith value is not taken
// dp[i][1] = ans of intial i values if ith value is  taken
// ans = max(dp[n - 1][0], dp[n - 1][1])
// 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)(nums.size());
        if (n == 1)
            return nums[0];
        int dp[n][2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                dp[i][j] = INT32_MIN;
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];
        for (int i = 2; i < n; i++) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = nums[i] + max(dp[i - 2][0], dp[i - 2][1]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};