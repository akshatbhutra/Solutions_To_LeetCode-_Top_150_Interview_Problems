// https://leetcode.com/problems/number-of-1-bits/
// APPROACH:
// iterate over all 32 bits and check if they are set.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (n & (1 << i))
                ans++;
        return ans;
    }
};