// https://leetcode.com/problems/search-a-2d-matrix-ii/
// approach
// do binary search over all rows OR columns

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)(matrix.size()), m = (int)(matrix[0].size());
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                }
                else if (matrix[i][mid] > target) 
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return false;
    }
};