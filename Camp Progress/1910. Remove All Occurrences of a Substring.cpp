// Question Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int sLen = s.size(), partLen = part.size();
        if (partLen > sLen) {
            return s;
        }
        
        string stringStack = "";
        for (char &currentLetter : s) {
            stringStack += currentLetter;
            if (stringStack.size() >= partLen && stringStack.back() == part.back()) {
                isPopPossible(stringStack, part, partLen);
            }   
        }
        
        return stringStack;
    }
    
    bool isPopPossible(string &stringStack, string &part, int &partLen) {
        for (int pIndex = partLen - 1, sIndex = stringStack.size() - 1; pIndex >= 0; pIndex--, sIndex--) {
            if (stringStack[sIndex] != part[pIndex]) {
                return false;
            }
        }
        
        stringStack.erase(stringStack.size() - partLen);
        return true;
    }
};