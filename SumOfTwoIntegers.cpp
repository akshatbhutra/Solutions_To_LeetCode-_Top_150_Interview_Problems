// https://leetcode.com/problems/sum-of-two-integers/
// Approach:
// Use formula:
// a + b = (a ^ b) + 2 * (a & b)

class Solution {
public:
    int getSum(int a, int b) {
        return ((a ^ b) + 2 * (a & b));        
    }
};