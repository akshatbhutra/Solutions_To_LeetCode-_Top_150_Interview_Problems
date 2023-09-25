// Approach:
// Maths!

class Solution {
public:
    int all_till(int k) {
        int ans = 0;
        if (k == 0)
            return 0;
        int p = 1;
        for (int i = 1; i <= k; i++) {
            p *= 26;
            ans += p;
        }
        return ans;
    }
    
    int calculate(int x, int y) {
        int p = 1;
        for (int i = 1; i <= y; i++)
            p = p * 26;
        return x * p;
    }
    
    int titleToNumber(string columnTitle) {
        int n = (int)(columnTitle.size());
        int ans = 0;
        ans += all_till(n - 1);
        for (int i = 0; i < n; i++) {
            int small = (columnTitle[i] - 'A');
            ans += calculate(small, n - 1 - i);
        }
        return ans + 1;
    }
};