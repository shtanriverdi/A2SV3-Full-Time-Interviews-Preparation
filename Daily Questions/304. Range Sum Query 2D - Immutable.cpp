// Question Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    int N, M;
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& mat) {
        matrix = mat;
        N = matrix.size();
        M = matrix[0].size();
        for (int j = 1; j < M; j++) {
           matrix[0][j] += matrix[0][j - 1]; 
        }
        for (int i = 1; i < N; i++) {
            matrix[i][0] += matrix[i - 1][0];
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int fullSum = matrix[row2][col2];
        int upperSum = (row1 - 1 >= 0) ? matrix[row1 - 1][col2] : 0;
        int leftSum = (col1 - 1 >= 0) ? matrix[row2][col1 - 1] : 0;
        int upperLeftCornerSum = (row1 - 1 >= 0 && col1 - 1 >= 0) ? matrix[row1 - 1][col1 - 1] : 0;
        return fullSum - upperSum - leftSum + upperLeftCornerSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */