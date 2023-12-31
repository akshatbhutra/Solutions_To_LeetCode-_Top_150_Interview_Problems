// https://leetcode.com/problems/4sum-ii/
// approach:
// Use map data structure to count sum of pairs of first two arrays
// then iterate over every pair of last 2 arrays

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = (int)(nums1.size());
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += mp[-nums3[i] - nums4[j]];
            }
        }
        return ans;
    }
};