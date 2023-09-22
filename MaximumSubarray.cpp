// Approach:
// sum[l,r] = p[r] - p[l - 1]
// for a fixed r, we want p[l - 1] as minimum as possible

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = (int)(nums.size());
        int p[n];
        p[0] = nums[0];
        for (int i = 1; i < n; i++)
                p[i] = p[i - 1] + nums[i];
        int ans = p[0], mini = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, p[i] - mini);
            mini = min(mini, p[i]);
        }
        return ans;
    }
};