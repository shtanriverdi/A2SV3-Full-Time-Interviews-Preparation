// Question Link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(), L = 0, R = len - 1;
        int answer = 0;
        while (L < R) {
            int h = min({height[L], height[R]});
            int w = R - L;
            int area = h * w;
            answer = max(answer, area);
            if (height[L] > height[R]) {
                R--;
            }
            else {
                L++;
            }
        }
        
        return answer;
    }
};