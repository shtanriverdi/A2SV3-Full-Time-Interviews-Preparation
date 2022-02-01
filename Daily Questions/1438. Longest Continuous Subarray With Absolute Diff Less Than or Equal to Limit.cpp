// Question Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> valCountMap;
        int result = 0, L = 0, len = nums.size();
        for (int R = 0; R < len; R++) {
            valCountMap[nums[R]]++;
            int minn = valCountMap.begin()->first; // First element
            int maxx = valCountMap.rbegin()->first; // Last element
            int diff = maxx - minn;
            if (diff > limit) {
                updateMap(valCountMap, L, nums, limit, diff);
            }
            int windowLen = R - L + 1;
            result = max(result, windowLen);
        }
        
        return result;
     }
    
    void updateMap(map<int, int> &valCountMap, int &L, vector<int> &nums, int &limit, int diff) {
        while (diff > limit) {            
            valCountMap[nums[L]]--;
            if (valCountMap[nums[L]] == 0) {
                valCountMap.erase(nums[L]);
            }
            L++;
            // Update diff
            diff = (valCountMap.begin()->first) - (valCountMap.rbegin()->first);
        }
    }
};