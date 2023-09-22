// Approach:
// Since constraints are small, so brute force is sufficient

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = (int)strs.size(), m = INT32_MAX;
        for (int i = 0; i < (int)(strs.size()); i++) {
            m = min(m, (int)(strs[i].size()));
        }
        int i = 0;
        while (i < m) {
            bool ok = 1;
            set<char> s;
            for (int j = 0; j < n; j++) {
                s.insert(strs[j][i]);
            }
            if ((int)(s.size()) != 1)
                break;
            i++;
        }
        return strs[0].substr(0, i);
    }
};