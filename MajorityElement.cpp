// Approach
// maintain frequency
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)(nums.size());
        map<int, int> f;
        for (auto &e: nums)
            f[e]++;
        for (auto &e: f)
            if (e.second > n / 2)
                return e.first;
        return -1;
    }
};