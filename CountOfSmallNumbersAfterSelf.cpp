// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// approach:
// use pbds order_of_key
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_multiset s;
        int n = (int)(nums.size());
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = s.order_of_key(nums[i]);
            s.insert(nums[i]);
        }
        return ans;
    }
};