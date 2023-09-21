// Approach:
// Fix one of the two numbers and binary search the other.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].first = nums[i];
            a[i].second = i;
        }
	    sort(a.begin(),a.end());
	    for (int i = 0;i < n;i++) {
		    int j = std::lower_bound(a.begin(), a.end(), make_pair(target - a[i].first, -1)) - a.begin();
		    if (j < n && j != i && a[j].first + a[i].first == target) 
			    return {a[i].second, a[j].second};
	    }
        return {0, 0};
    }
};