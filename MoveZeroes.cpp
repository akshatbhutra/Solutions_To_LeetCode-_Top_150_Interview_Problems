// https://leetcode.com/problems/move-zeroes/
// approach:
// iterate and whenever encounter a zero swap with next non zero value

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)(nums.size());
        set<int> s;
        for (int i = 0; i < n; i++)
            if(nums[i] != 0)
                s.insert(i);
        for (int i = 0; i < n; i++) {
            if(nums[i] == 0 && !s.empty()) {
                int non_zero_index;
                auto it = s.upper_bound(i);
                if (it == s.end())
                    break;
                non_zero_index = *it;
                s.erase(non_zero_index);
                swap(nums[i], nums[non_zero_index]);
            }
        }
    }
};
