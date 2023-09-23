// Approach:
// Start with initial values and continue

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(1);
        ans.push_back(cur);
        for (int i = 1; i < numRows; i++) {
            int cur_size = (int)(cur.size());
            vector<int> next;
            next.push_back(cur[0]);
            for (int i = 0; i < cur_size - 1; i++)
                next.push_back(cur[i] + cur[i + 1]);
            next.push_back(cur[cur_size - 1]);
            cur = next;
            ans.push_back(cur);
        }
        return ans;
    }
};