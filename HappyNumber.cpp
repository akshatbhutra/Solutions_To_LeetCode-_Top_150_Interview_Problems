// https://leetcode.com/problems/happy-number/
// approach:
// intuitively limit <= 100 steps

class Solution {
public:
    bool isHappy(int n) {
        int limit = 100, num = n;
        for (int i = 0; i < limit; i++) {
            int s = 0;
            while (num > 0) {
                s += ((num % 10) * (num % 10));
                num /= 10;
            }
            if (s == 1)
                return true;
            num = s;
        }
        return false;
    }
};