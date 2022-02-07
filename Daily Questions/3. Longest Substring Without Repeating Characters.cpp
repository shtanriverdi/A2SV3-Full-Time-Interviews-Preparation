// Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, R = 0, len = s.size(), result = 0;
        unordered_map<char, int> chrCntMap;
        for (; R < len; R++) {
            chrCntMap[s[R]]++;
            while (chrCntMap[s[R]] >= 2) {
                chrCntMap[s[L]]--;
                L++;
            }
            result = max(result, R - L + 1);
        }
        
        return result;
    }
};