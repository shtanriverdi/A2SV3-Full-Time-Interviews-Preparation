// Question Link: https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int len = arr.size();
        vector<int> result;
        for (int R = len; R > 0; R--) {
            int maxElemIdx = distance(begin(arr), max_element(begin(arr), begin(arr) + R));
            if (R - 1 != maxElemIdx) {
                result.push_back(maxElemIdx + 1);
                reverse(begin(arr), begin(arr) + maxElemIdx + 1);
                reverse(begin(arr), begin(arr) + R);
                result.push_back(R);
            }
        }
        
        return result;
    }
};