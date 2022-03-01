// Question Link: https://leetcode.com/problems/flood-fill/

// Iterative Implementation
class Solution {
private:
    vector<int> dirs = { 0, 1, 0, -1, 0 };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        
        int M = image.size();
        int N = image[0].size();
        
        int oldColor = image[sr][sc];
        
        stack<vector<int>> todoStack;
        todoStack.push({ sr, sc });
        
        while (!todoStack.empty()) {
            int i = todoStack.top()[0];
            int j = todoStack.top()[1];
            todoStack.pop();
            
            image[i][j] = newColor;
            
            for (int d = 1; d < 5; d++) {
                int ni = i + dirs[d];
                int nj = j + dirs[d - 1];
                if (inside(ni, nj, M, N) && image[ni][nj] == oldColor) {
                    todoStack.push({ ni, nj });
                }
            }
        }
        
        return image;
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    }
};

// Recursive Implementation
class Solution {
private:
    vector<int> dirs = { 0, 1, 0, -1, 0 };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int M = image.size();
        int N = image[0].size();
        if (image[sr][sc] == newColor) {
            return image;
        }
        dfs(image, sr, sc, newColor, image[sr][sc], M, N);
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int i, int j, int &newColor, int oldColor, int &M, int &N) {
        image[i][j] = newColor;
        for (int d = 1; d < 5; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d - 1];
            if (inside(ni, nj, M, N) && image[ni][nj] == oldColor) {
                dfs(image, ni, nj, newColor, oldColor, M, N);
            }
        }
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    }
};