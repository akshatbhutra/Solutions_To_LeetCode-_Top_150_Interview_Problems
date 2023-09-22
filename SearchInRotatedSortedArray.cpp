// Approach:
// 2 binary search [on 2 sorted parts]

class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = (int)(nums.size()), k;
         for (int i = 0; i < n - 1; i++) {
             if (nums[i] > nums[i + 1]) {
                 k = i;
                 break;
             }
         }

        int l = 0, r = k, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)  {
                ans = m;
                break;
            }
            else if (nums[m] < target)
                l = m + 1;
            else 
                r = m - 1;
        }
        if (ans != -1) 
            return ans;
        l = k + 1; 
        r = n - 1;
        ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)  {
                ans = m;
                break;
            }
            else if (nums[m] < target)
                l = m + 1;
            else 
                r = m - 1;
        }
        return ans;
    }
};