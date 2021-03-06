// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        priority_queue<int> pq;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }   
        }

        return pq.top();
    }
};