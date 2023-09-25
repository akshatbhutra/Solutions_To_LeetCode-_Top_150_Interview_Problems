// https://leetcode.com/problems/move-zeroes/
// approach:
// https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-%2B-clear-explanation
// snowball approach

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int snowBallSize = 0; 
        for (int i=0;i<nums.size();i++){
	        if (nums[i]==0){
                snowBallSize++; 
            }
            else if (snowBallSize > 0) {
	            swap(nums[i], nums[i - snowBallSize]);
            }
        }
    }
};
