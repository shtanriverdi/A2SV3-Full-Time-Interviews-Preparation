// Question Link: https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len, 0);
        stack<int> monoDecStack;
        for (int index = 0; index < len; index++) {
            while (!monoDecStack.empty() && temperatures[index] > temperatures[monoDecStack.top()]) {
                result[monoDecStack.top()] = index - monoDecStack.top();
                monoDecStack.pop();
            }
            monoDecStack.push(index);
        }
        return result;
    }
};