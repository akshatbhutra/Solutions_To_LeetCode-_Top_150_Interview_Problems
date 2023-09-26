// Approach:
// Observation: RDLU movement is repeating.
// The below pattern is repeating:
// going right then down then left then up and 
// 

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = (int)(matrix.size());
//         int n = (int)(matrix[0].size());
//         vector<int> ans;
//         int i = 0, j = 0;
//         ans.push_back(matrix[0][0]);
//         bool vis[m][n];
//         for (int i = 0; i < m; i++)
//                 for (int j = 0; j < n; j++)
//                     vis[i][j] = 0;
//         vis[0][0] = 1;
//         while (1) {
//             bool ok = 0;
//             // right
//             j++;
//             while (j < n && !vis[i][j]) {
//                 vis[i][j] = 1;
//                 ok = 1;
//                 ans.push_back(matrix[i][j]);
//                 j++;
//             }
//             j--;
//             // down
//             i++;
//             while (i < m && !vis[i][j]) {
//                 vis[i][j] = 1;
//                 ok = 1;
//                 ans.push_back(matrix[i][j]);
//                 i++;
//             }
//             i--;
//             j--;
//             // left
//             while (j >= 0 && !vis[i][j]) {
//                 vis[i][j] = 1;
//                 ok = 1;
//                 ans.push_back(matrix[i][j]);
//                 j--;
//             }
//             j++;
//             // up
//             i--;
//             while (i >= 0 && !vis[i][j]) {
//                 vis[i][j] = 1;
//                 ok = 1;
//                 ans.push_back(matrix[i][j]);
//                 i--;
//             }
//             i++;
//             if (!ok)
//                 break;
//         }
//         return ans;
//     }
// };

// https://leetcode.com/problems/spiral-matrix/discuss/3502826/BFS
class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int rr[] = {0, 1, 0, -1};
    int cc[] = {1, 0, -1, 0};
    int row = 0;
    int col = 0;

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> ans;
    visited[0][0] = 1;
    ans.push_back(matrix[0][0]);

    int index = 0;
    int count = 1;

    while (count < m * n)
    {
        int r = row + rr[index];
        int c = col + cc[index];

        if (r < n and c < m and r >= 0 and c >= 0 and !visited[r][c])
        {
            count++;
            ans.push_back(matrix[r][c]);
            visited[r][c] = 1;
            row = r;
            col = c;
        }
        else
        {
            index = (index + 1) % 4;
        }
    }
    return ans;
}
};