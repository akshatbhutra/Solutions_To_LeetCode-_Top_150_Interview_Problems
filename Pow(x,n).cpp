// Approach:
// Binary Exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        bool neg = 0;
        long long nn = n;
        if (nn < 0) {
            neg = 1;
            nn *= -1;
        }
        double ans = 1.0;
        while (nn > 0) {
            if (nn & 1LL)
                ans = ans * x;
            x = x * x;
            nn /= 2;
        }
        if (neg)
            ans = 1.0 / ans;
        return ans;
    }
};