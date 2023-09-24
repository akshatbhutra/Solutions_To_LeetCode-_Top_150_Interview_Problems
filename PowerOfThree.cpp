// https://leetcode.com/problems/power-of-three/
// approach
// atmost log3(n) iterations 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        if (n <= 2)
            return false;
        long long p = 1;
        int limit = 21; // log3(MAX)
        for (int i = 1; i <= limit; i++) {
            p *= 3;
            if (p == n) {
                return true;
            }
        }
        return false;
    }
};