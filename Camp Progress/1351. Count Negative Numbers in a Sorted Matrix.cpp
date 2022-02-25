// Question Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size(), negativeCount = 0;
        for (int i = 0; i < M; i++) {
            int leftMostNegativeIndex = binarySearch(grid[i]);
            if (leftMostNegativeIndex != -1) {
                negativeCount += N - leftMostNegativeIndex;
            }
        }
        
        return negativeCount;
    }
    
    int binarySearch(vector<int> &row) {
        int l = 0, r = row.size() - 1, m, leftMostNegativeIndex = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (row[m] < 0) {
                leftMostNegativeIndex = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return leftMostNegativeIndex;
    }
};