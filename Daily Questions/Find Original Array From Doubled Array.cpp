// Question Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        if (len % 2 != 0) {
            return {};
        }
        sort(begin(changed), end(changed));
        vector<int> original;
        for (int i = 0; i < len; i++) {
            if (changed[i] != -1) {
                auto it = lower_bound(begin(changed) + i + 1, end(changed), changed[i] * 2);
                if (it != end(changed) && (*it == changed[i] * 2)) {
                    original.push_back(changed[i]);
                    *it = -1;
                }
                else {
                    return {};
                }   
            }
        }
        
        return original;
    }
};