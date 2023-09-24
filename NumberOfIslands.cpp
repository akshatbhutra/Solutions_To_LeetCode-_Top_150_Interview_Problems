// https://leetcode.com/problems/number-of-islands/ 
// approach:
// Count no of connected components in a graph

class Solution {
public:
    int n, m;
    bool v[301][301];
    void dfs(int i, int j, vector<vector<char>>& grid) {
        v[i][j] = 1;
        if (i + 1 < n && !v[i + 1][j] && grid[i + 1][j] == '1')
            dfs(i + 1, j, grid);
        if (i - 1 >= 0 && !v[i - 1][j] && grid[i - 1][j] == '1')
            dfs(i - 1, j, grid);
        if (j + 1 < m && !v[i][j + 1] && grid[i][j + 1] == '1')
            dfs(i, j + 1, grid);
        if (j - 1 >= 0 && !v[i][j - 1] && grid[i][j - 1] == '1')
            dfs(i, j - 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        n = (int)(grid.size()), m = (int)(grid[0].size());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                v[i][j] = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!v[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
        return ans;
    }
};