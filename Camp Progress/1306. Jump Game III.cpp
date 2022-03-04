// Question Link: https://leetcode.com/problems/jump-game-iii

// DFS Recursion
class Solution {
public:
    bool canReach(vector<int>& arr, int cur) {
        if (cur < 0 || cur >= arr.size() || arr[cur] == -1) {
            return false;
        }
        
        int offset = arr[cur];
        if (offset == 0) {
            return true;
        }
        
        arr[cur] = -1;
        return canReach(arr, cur + offset) || canReach(arr, cur - offset);
    }
};

// BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> todo;
        todo.push(start);
        int N = arr.size();
        while (todo.size() > 0) {
            int curIdx = todo.front(), offset = arr[curIdx];
            todo.pop();
            if (arr[curIdx] == 0) {
                return true;
            }
            
            arr[curIdx] = -1;
            
            int r = curIdx + offset;
            if (r < N && arr[r] != -1) {
                todo.push(r);
            }
            
            int l = curIdx - offset;
            if (l >= 0 && arr[l] != -1) {
                todo.push(l);
            } 
        }
        
        return false;
    }
};
