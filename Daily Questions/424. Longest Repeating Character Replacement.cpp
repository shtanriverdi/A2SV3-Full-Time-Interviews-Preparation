// Question Link: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> countMap;
        int len = s.size(), L = 0, R = 0;
        for (; R < len; R++) {
            countMap[s[R]]++;
            bool isValid = isWindowValid(countMap, k);
            if (isValid == false) {
                countMap[s[L]]--;
                if (countMap[s[L]] == 0) {
                    countMap.erase(s[L]);
                }
                L++;
            }
        }
        
        return R - L;
    }
    
    bool isWindowValid(unordered_map<char, int> &countMap, int &k) {
        if (countMap.size() > k + 1) {
            return false;
        }
        
        pair<char, int> maxChar = { '*', -1 };
        int restSum = 0;
        for (auto &it : countMap) {
            if (it.second > maxChar.second) {
                maxChar = { it.first, it.second };
            }
            restSum += it.second;
        }
        
        restSum -= maxChar.second;
        return restSum <= k;
    }
};