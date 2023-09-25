// Approach1
// maintain frequency
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = (int)(nums.size());
//         map<int, int> f;
//         for (auto &e: nums)
//             f[e]++;
//         for (auto &e: f)
//             if (e.second > n / 2)
//                 return e.first;
//         return -1;
//     }
// };

// Approach2
// Think: majority element will always lie in middle in sorted array.

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = (int)(nums.size());
//         sort(nums.begin(), nums.end());
//         return nums[n / 2];
//     }
// };


// Approach3:
// Looks like election voting problem 
// where that candidate wins who get more than n / 2 votes
// fancy name is Boyer–Moore majority vote algorithm


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)(nums.size());
        int winner = nums[0], votes = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == winner) {
                votes++;
            }
            else {
                // winner is changing & again start fresh 
                // with new winner from 1 vote
                // eg. 4 4 4 3 3 3 ?
                // if ? = 3 then 3 will win
                // if ? = 4 then 4 will win
                // winner = 4, vote = 1
                // winner = 4, vote = 2
                // winner = 4, vote = 3
                // winner = 4, vote = 2
                // winner = 4, vote = 1
                // winner = 3, vote = 1 
                // winner = 4, vote = 1
                votes--;
                if (votes == 0) {
                    winner = nums[i] ;
                    votes = 1;
                }
            }
        }
        return winner;
    }
};