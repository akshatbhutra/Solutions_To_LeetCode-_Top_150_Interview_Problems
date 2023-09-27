// Approach:
// Greedy will not work for eg. 12 = 9 + 1 + 1 + 1 
// 12 = 4 + 4 + 4 (better)
// dp[i] = min squares needed to sum i

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = INT32_MAX;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int e = 1; e * e <= i; e++) {
                dp[i] = min(dp[i], dp[i - e * e] + 1);
            }    
        }
        return dp[n];
    }
};