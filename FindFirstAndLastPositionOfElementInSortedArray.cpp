// Approach:
// Use Binary Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (int)(nums.size());
        if (nums.empty())
            return {-1, -1};
        vector<int> ans;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (nums[m] >= target)
                r = m;
            else 
                l = m;
        }
        cout << "# " << r << '\n';
        ans.push_back((r < n && nums[r] == target ? r : -1));
        l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (nums[m] > target)
                r = m;
            else 
                l = m;
        }
        ans.push_back((l >= 0 && nums[l] == target ? l : -1));
        return ans;
    }
};