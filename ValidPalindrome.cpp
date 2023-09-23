// Approach:
// Simple Implementation

class Solution {
public:
    bool isPalindrome(string s) {
        int n = (int)(s.size());
        string t;
        for (int i = 0; i < n; i++)
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                t += s[i];
        int m = (int)t.size();
        for (int i = 0; i < m; i++)
            if (t[i] >= 'A' && t[i] <= 'Z')
                t[i] = (char)(t[i] + 32);
        bool ok = 1;
        for (int i = 0; i < m / 2; i++)
            if (t[i] != t[m - 1 - i])
                ok = 0;
        return (ok == 0 ? false : true);
    }
};