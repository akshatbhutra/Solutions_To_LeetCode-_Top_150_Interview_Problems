// Approach:
// Greedy
// If we will sell on day i best to purchase on lowest cost before it

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)(prices.size());
        int ans = 0, mini = prices[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};