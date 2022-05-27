// Question Link: https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_set<char> taken;
        
        for (int i = 0; i < s.size(); i++) {
            char sletter = s[i];
            char tletter = t[i];
            
            if (sMap.find(sletter) == sMap.end()) {
                if (taken.find(tletter) != taken.end()) {
                    return false;
                }
                sMap[sletter] = tletter;
                taken.insert(tletter);
            }        
            else {
                if (sMap[sletter] != tletter) {
                    return false;
                }
            }
        }
        
        return true;
    }
};