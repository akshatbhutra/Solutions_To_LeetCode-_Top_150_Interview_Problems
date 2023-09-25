// Approach:
// Without set data structure
// Maintain pointers and "bypass" duplicates
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)(nums.size());
        int cur_idx = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            i = j - 1;
            nums[cur_idx] = nums[i];
            cur_idx++;
        }
        return cur_idx;
    }
};