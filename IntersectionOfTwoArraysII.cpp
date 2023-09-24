// approach:
// maintain two frequency ararys and push min freq among two of an element in new array

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = (int)(nums1.size()), n2 = (int)(nums2.size());
        int m1 = *max_element(nums1.begin(), nums1.end());
        int m2 = *max_element(nums2.begin(), nums2.end());
        vector<int> f1(m1 + 1), f2(m2 + 1);
        for (auto &e: nums1) 
            f1[e]++;
        for (auto &e: nums2) 
            f2[e]++;
        vector<int> ans;
        for (int i = 0; i <= min(m1, m2); i++) {
            int mini = min(f1[i], f2[i]);
            for (int j = 0; j < mini; j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};