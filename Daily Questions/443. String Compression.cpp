// Question Link: https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        int cur = 0;
        while (cur < len) {
            int nextIdx = modify(cur, len, chars, chars[cur]);
            cur = nextIdx;
        }
        
        clean(chars, len);
        
        return chars.size();
    }
    
    void clean(vector<char> &chars, int &len) {
        int firstEmptyCharIdx = 0;
        for (int i = 0; i < len && chars[i] != '\0'; i++) {
            firstEmptyCharIdx++;
        }
        
        for (int i = firstEmptyCharIdx + 1; i < len; i++) {
            if (chars[i] != '\0') {
                swap(chars[firstEmptyCharIdx], chars[i]);
                firstEmptyCharIdx++;
            }
        }
        
        int popCount = len - firstEmptyCharIdx;
        while (popCount > 0) {
            chars.pop_back();
            popCount--;
        }
    }
    
    int modify(int startIdx, int len, vector<char> &chars, char c) {
        int count = 0;
        int endIdx = startIdx;
        for (int i = startIdx; i < len && chars[i] == c; i++) {
            count++;
            endIdx++;
            chars[i] = '\0';
        }
        chars[startIdx] = c;
        startIdx++;
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[startIdx] = c;
                startIdx++;
            }
        }
        return endIdx;
    }
};