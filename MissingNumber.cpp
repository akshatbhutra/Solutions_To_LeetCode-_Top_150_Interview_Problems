// https://leetcode.com/problems/missing-number/
// approach
// use idea sum(1..n) = n*(n + 1) / 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)(nums.size());
        int s = accumulate(nums.begin(), nums.end(), 0);
        return ((n * (n + 1)) / 2 - s);
    }
};