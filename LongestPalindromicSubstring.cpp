// Approach:
// define following:
// dp[i][j] = 1 if s[i...j] is a palindrome, else 0
// Main observation is s[i...j] is a palindrome iff s[i]=s[j] && s[i+1...j-1] is a palindrome

class Solution {
public:
    string longestPalindrome(string s) {
        // start = starting position of resultant answer string & len is its length
        int n = s.size(), start, len = 1;
        bool dp[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) 
                dp[i][j] = 0;
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) 
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                len = 2;
                start = i;
            }
        for (int k = 3; k <= n; k++)
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = 1;
                    len = k;
                    start = i;
                }
            }
        return s.substr(start, len);
    }
};

// Approach : Expand From Centers O(n * n) time but O(1) space

