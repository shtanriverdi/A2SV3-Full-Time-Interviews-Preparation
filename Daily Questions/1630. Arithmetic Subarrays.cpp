// Question Link: https://leetcode.com/problems/arithmetic-subarrays/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int M = l.size();
        vector<bool> result(M, false);
        for (int i = 0; i < M; i++) {
            int start = l[i];
            int end = r[i];
            vector<int> subVec = { nums.begin() + start, nums.begin() + end + 1 };
            sort(subVec.begin(), subVec.end());
            result[i] = isArithmeticSequence(subVec);
        }
        
        return result;
    }
    
    bool isArithmeticSequence(vector<int> &sorted) {
        int diff = sorted[1] - sorted[0];
        for (int i = 2; i < sorted.size(); i++) {
            if (sorted[i] - sorted[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};