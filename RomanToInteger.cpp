// https://leetcode.com/problems/roman-to-integer/
// approach
// subtract the character value if it is followed by bigger value
// else add

class Solution {
public:
    int value(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else
            return 1000;
    }
    int romanToInt(string s) {
        int n = (int)(s.size()), ans = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && value(s[i]) < value(s[i + 1]))
               ans -= value(s[i]);
            else
                ans += value(s[i]);
        }
        return ans;
    }   
};