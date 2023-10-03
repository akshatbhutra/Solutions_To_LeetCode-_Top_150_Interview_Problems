// Approach:
// sum[l,r] = p[r] - p[l - 1]
// for a fixed r, we want p[l - 1] as minimum as possible
// O(1) space

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = (int)(nums.size());
        int p = 0;
        int ans = INT32_MIN, mini = 0;
        for (int i = 0; i < n; i++) {
            p += nums[i];
            ans = max(ans, p - mini);
            mini = min(mini, p);
        }
        return ans;
    }
};