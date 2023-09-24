// approach:
// sort by frequency using map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> f;
        map<int, int> fr;
        int n = (int)(nums.size());
        for (auto &e: nums)
            fr[e]++;
        for (auto &e: fr)
            f.push_back({e.second, e.first});
        sort(f.rbegin(), f.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(f[i].second);
        return ans;
    }
};