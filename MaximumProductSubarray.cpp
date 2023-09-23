// approach:
// product[l...r] = prod[1....r] / prod[1....l-1]
// for a fixed r choose prod[1.....l-1]  greedily based on sign.
// Whenever encounter zeros, start fresh.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)(nums.size()), ans = INT32_MIN;
        if (n == 0)
            return 0;
        int p = 1, cur_max_pos = 1, cur_max_neg = INT32_MIN;
        for (int i = 0; i < n; i++) { 
                if (nums[i] == 0) {
                    ans = max(ans, 0);
                    while (i < n && nums[i] == 0)
                        i++;
                    i--;
                    p = 1;
                    cur_max_pos = 1;
                    cur_max_neg = INT32_MIN;
                    continue;
                }
                p *= nums[i];
                if (p > 0) {
                    ans = max(ans, p);
                    cur_max_pos = max(cur_max_pos, p);
                }
                else {
                        if(cur_max_neg != INT32_MIN) {   
                            ans = max(ans, p / cur_max_neg);
                        }
                        ans = max(ans, p / cur_max_pos);
                        cur_max_neg = max(cur_max_neg, p);
                }
            }
            return ans;
    }
};