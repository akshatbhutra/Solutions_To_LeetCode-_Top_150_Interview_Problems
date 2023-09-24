// https://leetcode.com/problems/reverse-bits/
// Approach:
// Iterate over bits and sum their contribution

class Solution {
public:
    string to_binary(uint32_t n) {
            string ans;
            while (n > 0) {
                if (n & 1)
                    ans = ans + '1';
                else
                    ans = ans + '0';
                n >>= 1;
            }
        while((int)ans.size() != 32) 
            ans = ans + '0';
        return ans;
    }
    
    uint32_t to_deci(string b) {
        uint32_t ans = 0;
        reverse(b.begin(), b.end());
        for (int i = 0; i < (int)(b.size()); i++)
            if (b[i] == '1')
                ans += (1 << i);
        return ans;
    }
    
    uint32_t reverseBits(uint32_t n) {
        return to_deci(to_binary(n));
    }
};