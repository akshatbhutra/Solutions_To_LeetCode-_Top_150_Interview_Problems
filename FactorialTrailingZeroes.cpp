// Problem: https://leetcode.com/problems/factorial-trailing-zeroes/
// Approach
// # of trailing zeros in fact(n) = n / 5 + n / 25 + n / 125 + ....
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i *= 5)
            ans += (n / i);
        return ans;
    }
};