// approach:
// binary search the answer
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        else if (x == 1)
            return 1;
        long long l = 0, r = x;
        while (r - l > 1) {
            long long m = (l + r) / 2;
            if (m * m > x)
                r = m;
            else 
                l = m;
        }
        return r - 1;
    }
};