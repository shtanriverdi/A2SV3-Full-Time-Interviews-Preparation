// Question Link: https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int len = heights.size(), rightMostIndex = 0, d;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 1; i < len; i++) {
            d = heights[i] - heights[i - 1];
            if (d > 0) {
                // Try to use ladders first
                if (ladders > 0) {
                    ladders--;
                    minHeap.push(d);
                    rightMostIndex = i;
                }
                else {
                    if (minHeap.size() > 0) {
                        int exchanceCost = minHeap.top();
                        if (bricks >= exchanceCost && bricks >= d && d < exchanceCost) {
                            bricks -= d;
                            rightMostIndex = i;
                        }
                        else if (bricks >= exchanceCost) {
                            bricks -= minHeap.top();
                            minHeap.pop();
                            rightMostIndex = i;
                            minHeap.push(d);
                        }
                        else if (bricks < exchanceCost && bricks >= d) {
                            bricks -= d;
                            rightMostIndex = i;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else {
                rightMostIndex = i;
            }
        }
        
        return rightMostIndex;
    }
};