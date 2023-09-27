// Approach:
// Recursion

class Solution {
public:
    vector<string> ans;
    void dfs(int openAvailable, int closeAvailable, string s) {
        if (openAvailable + closeAvailable == 0) {
            ans.push_back(s);
            return;
        }
        if (openAvailable > 0) {
            dfs(openAvailable - 1, closeAvailable, s + "(");
        }
        if (closeAvailable > openAvailable) {
            dfs(openAvailable, closeAvailable - 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return ans;
    }
};

// Another implementation

// class Solution {
// public:
//     int nn;
//     vector<string> ans;
//     void dfs(int openUsed, int closeUsed, string s) {
//         if (openUsed + closeUsed == 2 * nn) {
//             ans.push_back(s);
//             return;
//         }
//         if (openUsed < nn)
//             dfs(openUsed + 1, closeUsed, s + "(");
//         if (closeUsed < openUsed)
//             dfs(openUsed, closeUsed + 1, s + ")");
//     }
//     vector<string> generateParenthesis(int n) {
//         nn = n;
//         dfs(0, 0, "");
//         return ans;
//     }
// };