// Approach:
// Fix two values and binary search the third
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = make_pair(nums[i], i);
	    sort(a.begin(), a.end());
        map<pair<int, pair<int, int>> , bool > vis;
	    for (int i = 0; i < n - 2; i++)
		    for (int j = i + 1; j < n - 1; j++) {
			    int k = lower_bound(j + 1 + a.begin(), a.end(), make_pair(-a[i].first-a[j].first, -1)) - a.begin();
			    if (k < n && (a[k].first + a[j].first + a[i].first == 0)) {
                    if (!vis[{nums[a[i].second], {nums[a[j].second], nums[a[k].second]}}])
                        ans.push_back({nums[a[i].second], nums[a[j].second], nums[a[k].second]});
                    vis[{nums[a[i].second], {nums[a[j].second], nums[a[k].second]}}] = 1;
                }
		}
        return ans;
    }
};