// https://leetcode.com/problems/sliding-window-maximum/
// approach
// We will maintain a sliding window of size k and 
// keep track of maximum in multiset.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = (int)(nums.size());
        multiset<int, greater<int>> s;
        for (int i = 0; i < k - 1; i++)
            s.insert(nums[i]);
        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            if (i >= k)
                s.erase(s.find(nums[i - k]));
            s.insert(nums[i]);
            ans.push_back(*(s.begin()));
        }
        return ans;
    }
};