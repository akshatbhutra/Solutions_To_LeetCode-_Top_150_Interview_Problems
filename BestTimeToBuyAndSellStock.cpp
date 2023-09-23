// Approach:
// Greedy
// If we will purchase on day i then will sell on that day [i+1...n-1]
// when price is highest

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)(prices.size());
        int ans = 0;
        int maxi[n];
        maxi[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxi[i] = max(prices[i], maxi[i + 1]);
        }
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, maxi[i + 1] - prices[i])   ;
        }
        return ans;
    }
};