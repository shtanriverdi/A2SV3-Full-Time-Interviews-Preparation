// Question Link: https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numOfNodes = points.size();
        
        vector<int> dsu(numOfNodes);
        vector<int> height(numOfNodes, 1);
        for (int i = 0; i < numOfNodes; i++) {
            dsu[i] = i;
        }
        
        vector<pair<int, pair<int, int>>> allEdges;
        for (int i = 0; i < numOfNodes; i++) {
            for (int j = i + 1; j < numOfNodes; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                allEdges.push_back({ distance, { i, j } });
            }
        }
        
        sort(begin(allEdges), end(allEdges));
        
        int minCost = 0;
        int currentIndex = 0;
        
        while (currentIndex < allEdges.size() && numOfNodes > 1) {
            int a = allEdges[currentIndex].second.first;
            int b = allEdges[currentIndex].second.second;
            int cost = allEdges[currentIndex].first;
            
            bool hasMerged = hasUnioned(a, b, dsu, height);
            
            numOfNodes -= (hasMerged == true);
            minCost += (hasMerged == true) ? cost : 0;
            
            currentIndex++;
        }
        
        return minCost;
    }
    
    int find(int cur, vector<int> &dsu) {
        if (cur == dsu[cur]) {
            return cur;
        }
        dsu[cur] = find(dsu[cur], dsu);
        return dsu[cur];
    }
    
    bool hasUnioned(int &a, int &b, vector<int> &dsu, vector<int> &height) {
        int A = find(a, dsu);
        int B = find(b, dsu);
        if (A == B) {
            return false;
        }
        
        if (height[A] > height[B]) {
            dsu[B] = dsu[A];
        }
        else if (height[A] < height[B]) {
            dsu[A] = dsu[B];
        }
        else {
            dsu[B] = dsu[A];
            height[A]++;
        }
        
        return true;
    }
};