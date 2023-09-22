// Approach:
// Brute force Implementation: handle all 4 cases seperately
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = (int)(digits.size());
        map<char, vector<string> > m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};
        vector<string> ans;
        if (n == 4) {
            for (auto &a: m[digits[0]])
                for (auto &b: m[digits[1]])
                    for (auto &c: m[digits[2]])
                        for (auto &d: m[digits[3]])
                            ans.push_back(a + b + c + d);
        }
        else if (n == 3) {
            for (auto &a: m[digits[0]])
                for (auto &b: m[digits[1]])
                    for (auto &c: m[digits[2]])
                        ans.push_back(a + b + c);
        }
        else if (n == 2) {
            for (auto &a: m[digits[0]])
                for (auto &b: m[digits[1]])
                    ans.push_back(a + b);
        }
        else if (n == 1) {
            return m[digits[0]];
        }
        return ans;
    }
};