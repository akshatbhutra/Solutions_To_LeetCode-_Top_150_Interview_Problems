// Approach:
// Store rows and columns containing zero
// Space = O(m + n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = (int)(matrix.size()), m = (int)(matrix[0].size());
        set<int> r, c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
        for (auto &e: r)
            for (int j = 0; j < m; j++)
                matrix[e][j] = 0;
        for (auto &e: c)
            for (int j = 0; j < n; j++)
                matrix[j][e] = 0;
    }
};