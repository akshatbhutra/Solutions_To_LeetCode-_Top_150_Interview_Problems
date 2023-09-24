// https://leetcode.com/problems/coin-change/
// approach
// dp[i] = no of coins to make i amount
// transition dp[i] = (dp[i - j] + 1) if we use coin of value j

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)(coins.size());
        long long dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) 
                dp[i] = INT32_MAX;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if (dp[amount] == INT32_MAX)
            dp[amount] = -1;
        return dp[amount];
    }
};