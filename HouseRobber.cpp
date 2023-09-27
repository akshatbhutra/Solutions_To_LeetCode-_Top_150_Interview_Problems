// https://leetcode.com/problems/house-robber/
// approach:
//  dp[i] = ans till initial i values

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = (int)(nums.size());
//         if (n == 1)
//             return nums[0];
//         int dp[n];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i = 2; i < n; i++) {
//             dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
//         }
//         return dp[n - 1];
//     }
// };

// O(1) space

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)(nums.size());
        if (n == 1)
            return nums[0];
        // int dp[n];
        int cur, prev = max(nums[0], nums[1]), prev_prev = nums[0];
        for (int i = 2; i < n; i++) {
            cur = max(prev, nums[i] + prev_prev);
            prev_prev = prev;
            prev = cur;
        }
        return prev;
    }
};