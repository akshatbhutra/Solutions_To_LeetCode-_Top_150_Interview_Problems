// https://leetcode.com/problems/reverse-string/
// approach:
// swap s[i] with s[n - 1 - i] for i < n / 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = (int)(s.size());
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - 1 - i]);
    }
};