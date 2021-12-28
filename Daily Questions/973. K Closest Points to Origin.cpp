// Question Link: https://leetcode.com/problems/k-closest-points-to-origin/

// Initial Solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<double, vector<int>>> distPQ;
        for (vector<int> &point : points) {
            distPQ.push({ getEucDist(point) * -1.0, point });
        }
        for (; k > 0; k--, distPQ.pop()) {
            result.push_back(distPQ.top().second);          
        }
        return result;
    }
    
    double getEucDist(vector<int> &point) {
        return sqrt(((point[0] - 0) * (point[0] - 0)) + ((point[1] - 0) * (point[1] - 0))) * 1.0;
    } 
};

// Shorter Version
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<double, vector<int>>> distPQ;
        for (vector<int> &point : points) {
            distPQ.push({ (sqrt(((point[0] - 0) * (point[0] - 0)) + ((point[1] - 0) * (point[1] - 0))) * 1.0) * -1.0, point });
        }
        for (; k > 0; k--, distPQ.pop()) {
            result.push_back(distPQ.top().second);          
        }
        return result;
    }
};