// Question Link: https://leetcode.com/problems/find-a-peak-element-ii/

// O(logN) * O(logM)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();

        int li = 0, hi = M - 1, im;
        int lj = 0, hj = N - 1, jm;
        
        vector<int> invalid = { -1, -1 }, result = invalid;
        
        while (result == invalid) {
            im = li + (hi - li) / 2;
            jm = lj + (hj - lj) / 2;
            
            int up = (im - 1 >= 0) ? mat[im - 1][jm] : INT_MIN;
            int down = (im + 1 < M) ? mat[im + 1][jm] : INT_MIN;
            int right = (jm + 1 < N) ? mat[im][jm + 1] : INT_MIN;
            int left = (jm - 1 >= 0) ? mat[im][jm - 1] : INT_MIN;
            
            int maxNeighbor = max({ up, down, left, right });
            
            if (mat[im][jm] > maxNeighbor) {
                return { im, jm };
            }
            
            li = (maxNeighbor == down) ? im + 1 : li;
            hi = (maxNeighbor == up) ? im - 1 : hi;
            li = (hi < li) ? hi : li;
            hi = (li > hi) ? li : hi;
            
            lj = (maxNeighbor == right) ? jm + 1 : lj;
            hj = (maxNeighbor == left) ? jm - 1 : hj;
            lj = (hj < lj) ? hj : lj;
            hj = (lj > hj) ? lj : hj;
        }
        
        return result;
    }
};

// O(M + N)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        
        vector<int> result = { -1, -1 }, invalid = { -1, -1 };
        int i = 0, j = 0;
        
        while (result == invalid) {
            int up = (i - 1 >= 0) ? mat[i - 1][j] : INT_MIN;
            int down = (i + 1 < M) ? mat[i + 1][j] : INT_MIN; 
            int left = (j - 1 >= 0) ? mat[i][j - 1] : INT_MIN;
            int right = (j + 1 < N) ? mat[i][j + 1] : INT_MIN;
            
            if (mat[i][j] > up && mat[i][j] > down && mat[i][j] > left && mat[i][j] > right) {
                return { i, j };
            }
            
            int maxx = max({ up, down, left, right });
            i = (maxx == up) ? i - 1 : (maxx == down ? i + 1 : i);
            j = (maxx == left) ? j - 1 : (maxx == right ? j + 1 : j);
        }
        
        return result;
    }
};


// O(MlogN)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        vector<int> invalid = { -1, -1 }, result = { 0, 0 };
        for (int i = 0; i < M; i++) {
            result = binarySearch(mat, mat[i], i, 1453, 0, N - 1, M, N, invalid);
            if (result != invalid) {
                break;
            }
        }
        
        return result;
    }
    
    vector<int> binarySearch(vector<vector<int>>& mat, vector<int> &row, int i, int j, int l, int r, int &M, int &N, vector<int> &invalid) {
        if (l > r) {
            return { -1, -1 };
        }
        
        int m = l + (r - l) / 2;
        j = m;
        
        int up = (i - 1) >= 0 ? mat[i - 1][j] : INT_MIN;
        int down = (i + 1) < M ? mat[i + 1][j] : INT_MIN;
        int right = (j + 1) < N ? mat[i][j + 1] : INT_MIN;
        int left = (j - 1) >= 0 ? mat[i][j - 1] : INT_MIN;
        
        if (mat[i][m] > up && mat[i][m] > down && mat[i][m] > right && mat[i][m] > left) {
            return { i , m };
        }
        
        if (right > left) {
            return binarySearch(mat, row, i, j, m + 1, r, M, N, invalid);
        }
        return binarySearch(mat, row, i, j, l, m - 1, M, N, invalid);
    }
};
