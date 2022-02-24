// Question Link: https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stonesPQ;
        for (int &stone : stones) {
            stonesPQ.push(stone);
        }
        
        while (stonesPQ.size() > 1) {
            int y = stonesPQ.top();
            stonesPQ.pop();
            
            int x = stonesPQ.top();
            stonesPQ.pop();
            
            int collision = y - x;
            if (collision != 0) {
                stonesPQ.push(collision);
            }
        }
        
        return stonesPQ.empty() ? 0 : stonesPQ.top();
    }
};