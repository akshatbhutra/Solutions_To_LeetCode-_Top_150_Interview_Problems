// Approach:
// Use Dynamic Programming
// Define dp[i] = 1 if i is reachable from 1 else no
// And then transition would be dp[i] = 1 if dp[j] and j + step >= i for j < i

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)(nums.size());
        vector<bool> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (dp[j] && j + nums[j] >= i) {
                        dp[i] = 1;
                        break;
                    }
                }   
        }
        if (dp[n - 1])
            return true;
        return false;
    }
};