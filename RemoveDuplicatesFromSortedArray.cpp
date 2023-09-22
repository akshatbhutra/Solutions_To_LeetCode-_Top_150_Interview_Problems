// Approach:
// Use a set data structure to store unique values in sorted order
// then overwrite the unique values in the beginning of array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (auto &e: nums)
                s.insert(e);
        int k = (int)(s.size());
        for (int i = 0; i < k; i++) {
            nums[i] = *(s.begin());
            s.erase(s.begin());
        }
        return k;
    }
};