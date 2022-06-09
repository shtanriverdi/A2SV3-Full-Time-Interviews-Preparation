// Question Link: https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> grid(n, string(n, '.'));
        
        int len = n;
        unordered_set<int> positiveSet, negativeSet, columnSet;
        placeQueens(0, result, grid, positiveSet, negativeSet, columnSet, len);
        
        return result;
    }
    
    void placeQueens(int r, vector<vector<string>> &result, vector<string> &grid, unordered_set<int> &positiveSet, unordered_set<int> &negativeSet, unordered_set<int> &columnSet, int &len) {
        if (r == len) {
            result.push_back(grid);
            return;
        }
        
        for (int c = 0; c < len; c++) {
            if (isValid(r, c, positiveSet, negativeSet, columnSet)) {
                grid[r][c] = 'Q';
                positiveSet.insert(r + c);
                negativeSet.insert(r - c);
                columnSet.insert(c);

                placeQueens(r + 1, result, grid, positiveSet, negativeSet, columnSet, len);

                grid[r][c] = '.';
                positiveSet.erase(r + c);
                negativeSet.erase(r - c);
                columnSet.erase(c);                    
            }
        }
    }
    
    bool isValid(int r, int c, unordered_set<int> &positiveSet, unordered_set<int> &negativeSet, unordered_set<int> &columnSet) {
        bool isInsidePositiveLine = (positiveSet.find(r + c) == positiveSet.end());
        bool isInsideNegativeLine = (negativeSet.find(r - c) == negativeSet.end());
        bool isInsideColumnLine = (columnSet.find(c) == columnSet.end());
        
        return isInsidePositiveLine && isInsideNegativeLine && isInsideColumnLine;
    }
};