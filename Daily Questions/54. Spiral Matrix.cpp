// Question Link: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<int> spiralMatrix;
        
        int dir = 0;
        int i = 0, j = 0;
        int cells = M * N;
        while (cells > 0) {
            while (isInside(i, j, M, N, matrix)) {
                spiralMatrix.push_back(matrix[i][j]);
                matrix[i][j] = 1453;
                i += dirs[dir][0];
                j += dirs[dir][1];
            }
            
            i -= dirs[dir][0];
            j -= dirs[dir][1];
            
            dir = (dir + 1) % 4;
            
            i += dirs[dir][0];
            j += dirs[dir][1];
            
            cells--;
        }
        
        return spiralMatrix;
    }
    
    bool isInside(int i, int j, int &M, int &N, vector<vector<int>> &matrix) {
        if (i < 0 || i >= M || j < 0 || j >= N || matrix[i][j] == 1453) {
            return false;
        }
        return true;
    }
};