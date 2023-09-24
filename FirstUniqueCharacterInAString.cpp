// https://leetcode.com/problems/first-unique-character-in-a-string/
// approach:
// maintain a frequency array of size 26
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26);
        for (auto &ch: s)
            f[ch - 'a']++;
        for (int i = 0; i < (int)(s.size()); i++)
            if (f[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};