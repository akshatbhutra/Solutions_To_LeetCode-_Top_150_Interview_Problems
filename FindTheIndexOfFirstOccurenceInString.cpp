// Approach:
// Pattern matching: Use inbuilt method string::find
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};