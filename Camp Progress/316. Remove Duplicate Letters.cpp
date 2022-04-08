// Question Link: https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        unordered_map<char, int> lastIndexMap;
        for (int i = 0; i < len; i++) {
            lastIndexMap[s[i]] = i;
        }
        
        int begin = 0, end = getMinIndex(lastIndexMap);
        int n = lastIndexMap.size();
        string result(n, '\0');
        unordered_set<char> taken;
        
        // For each slot letter of the result
        for (int i = 0; i < n; i++) {
            char curSmallest = smallestLetterInRange(begin, end, s, lastIndexMap);
            
            result[i] = curSmallest;
            lastIndexMap.erase(curSmallest);
            
            if (s[end] == curSmallest) {
                end = getMinIndex(lastIndexMap);
            }
        }
        
        return result;
    }
    
    int getMinIndex(unordered_map<char, int> &lastIndexMap) {
        int minIndex = INT_MAX;
        for (auto &it : lastIndexMap) {
            minIndex = min(minIndex, it.second);
        }
        
        return minIndex == INT_MAX ? -1 : minIndex;
    }
    
    char smallestLetterInRange(int &begin, int &end, string &s, unordered_map<char, int> &lastIndexMap) {
        char smallestLetter = 'z' + 1;
        for (int i = begin; i <= end; i++) {
            if (lastIndexMap.find(s[i]) != lastIndexMap.end() && s[i] < smallestLetter) {
                smallestLetter = s[i];
                begin = i + 1;
            }
        }
        
        return smallestLetter;
    }
};