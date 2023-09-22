// Approach:
// Use sorting and map data structure

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        map<string, vector<string>> m;
        int n = (int)(strs.size());
        vector<pair<string, string> > v;
        for (int i = 0; i < n; i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(strs[i]);
        }
        for (auto &s: m)
            ans.push_back(s.second);
        return ans;
    }
};