// Question Link: https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string &num, int k) {
        int len = num.size(), windowLen = len - k;
        string result = "";
        if (len == k) {
            return "0";
        }
        
        int R = len - windowLen;
        deque<char> monoDecQueue;
        for (int i = 0; i <= R; i++) {
            while (!monoDecQueue.empty() && num[i] < monoDecQueue.back()) {
                monoDecQueue.pop_back();
            }
            monoDecQueue.push_back(num[i]);
        }
        
        result += monoDecQueue.front();
        monoDecQueue.pop_front();
        R++;
        
        while (R < len) {
            while (!monoDecQueue.empty() && num[R] < monoDecQueue.back()) {
                monoDecQueue.pop_back();
            }
            monoDecQueue.push_back(num[R]);
            
            result += monoDecQueue.front();
            monoDecQueue.pop_front();
            R++;
        }
        
        int i = 0;
        for (; i < result.size() && result[i] == '0'; i++) {}
        string cleanResult = string(begin(result) + i, end(result));
        
        return cleanResult == "" ? "0" : cleanResult;
    }
};