// https://leetcode.com/problems/rotate-array/
// Approach: Use extra array and rotate

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)(nums.size());
        k = k % n;
        vector<int> t;
        for (int i = n - k; i < n; i++)
            t.push_back(nums[i]);
        for (int i = 0; i < n - k; i++)
            t.push_back(nums[i]);
        for (int i = 0; i < n; i++)
            nums[i] = t[i];
    }
};