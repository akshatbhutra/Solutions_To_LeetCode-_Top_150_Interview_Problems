// Approach:
// Observation: RDLU movement is repeating.
// The below pattern is repeating:
// going right then down then left then up.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int)(matrix.size());
        int n = (int)(matrix[0].size());
        vector<int> ans;
        int i = 0, j = 0;
        ans.push_back(matrix[0][0]);
        bool vis[m][n];
        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    vis[i][j] = 0;
        vis[0][0] = 1;
        while (1) {
            bool ok = 0;
            // right
            j++;
            while (j < n && !vis[i][j]) {
                vis[i][j] = 1;
                ok = 1;
                ans.push_back(matrix[i][j]);
                j++;
            }
            j--;
            // down
            i++;
            while (i < m && !vis[i][j]) {
                vis[i][j] = 1;
                ok = 1;
                ans.push_back(matrix[i][j]);
                i++;
            }
            i--;
            j--;
            // left
            while (j >= 0 && !vis[i][j]) {
                vis[i][j] = 1;
                ok = 1;
                ans.push_back(matrix[i][j]);
                j--;
            }
            j++;
            // up
            i--;
            while (i >= 0 && !vis[i][j]) {
                vis[i][j] = 1;
                ok = 1;
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;
            if (!ok)
                break;
        }
        return ans;
    }
};