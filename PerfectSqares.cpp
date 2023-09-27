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
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
            dp[i * i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (auto &e: squares) {
                if (e <= i)
                    dp[i] = min(dp[i], dp[i - e] + 1);
                else 
                    break;
            }    
        }
        return dp[n];
    }
};