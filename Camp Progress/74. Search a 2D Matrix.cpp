// Question Link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0, r = M - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            int lv = matrix[m][0], rv = matrix[m][N - 1];
            if (target >= lv && target <= rv) {
                return binary_search(begin(matrix[m]), end(matrix[m]), target);
            }
            else if (target < lv) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return false;
    }
};