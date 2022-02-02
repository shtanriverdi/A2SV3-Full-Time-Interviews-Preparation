// Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> right(len, len);
        stack<int> monoIncStackRight;
        for (int i = 0; i < len; i++) {
            while (!monoIncStackRight.empty() && heights[i] < heights[monoIncStackRight.top()]) {
                right[monoIncStackRight.top()] = i;
                monoIncStackRight.pop();
            }
            monoIncStackRight.push(i);
        }
        
        vector<int> left(len, -1);
        stack<int> monoIncStackLeft;
        for (int i = len - 1; i >= 0; i--) {
            while (!monoIncStackLeft.empty() && heights[i] < heights[monoIncStackLeft.top()]) {
                left[monoIncStackLeft.top()] = i;
                monoIncStackLeft.pop();
            }
            monoIncStackLeft.push(i);
        }
        
        int result = 0;
        for (int i = 0; i < len; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            result = max(area, result);
        }
        
        return result;
    }
};