// Approach:
// clean code
// Sort strings and it is sufficient to compare the first & last strings

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = (int)strs.size(), m = INT32_MAX;
        for (int i = 0; i < (int)(strs.size()); i++) {
            m = min(m, (int)(strs[i].size()));
        }
        sort(strs.begin(), strs.end());
        string ans = "";
        for (int i = 0; i < m; i++) {
            if (strs[0][i] == strs[n - 1][i])
                ans += strs[0][i];
            else
                break;
        }
        return ans;
    }
};