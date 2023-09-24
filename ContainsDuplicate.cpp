// https://leetcode.com/problems/contains-duplicate/
// approach:
// Use set data structure.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (auto &e: nums)
            s.insert(e);
        if((int)(s.size()) == (int)(nums.size()))
            return false;
        return true;
    }
};