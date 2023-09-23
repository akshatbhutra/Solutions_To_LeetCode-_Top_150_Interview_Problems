// approach
// do xor of all as x ^ x = 0 and 0 ^ x = x

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto &e: nums)
            x ^= e;
        return x;
    }
};