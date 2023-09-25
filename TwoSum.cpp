// https://leetcode.com/problems/two-sum/
// Approach1:
// Fix one of the two numbers and binary search the other.
// Approach2:
// Maintain Two Pointers after sorting
// Approach3:
// Use a map(unordered) data structure

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
		    int j = std::lower_bound(a.begin() + i + 1, a.end(), make_pair(target - a[i].first, -1)) - a.begin();
		    if (j < n && a[j].first + a[i].first == target) 
			    return {a[i].second, a[j].second};
	    }
        return {0, 0};
    }
};

// Approach2:
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<pair<int, int>> v;
//         for (int i = 0; i < n; i++)
//             v.push_back({nums[i], i});
//         sort(v.begin(), v.end());
//         int l = 0, r = n -1;
//         while (l < r) {
//             int s = v[l].first + v[r].first;
//             if (s == target) {
//                 return {v[l].second, v[r].second};
//             }
//             else if (s > target) {
//                 r--;
//             }
//             else {
//                 l++;
//             }
//         }
//         return {-1, -1};
//     }
// };


// Approach3:
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> map;
//         for(int i = 0; i < nums.size(); ++i) {
//             if(map.find(target - nums[i]) == map.end()) {
//                 map[nums[i]] = i;
//             }
//             else {
//                 return {i, map[target - nums[i]]};
//             }
//         }
//         return {};
//     }
// };