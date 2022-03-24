// Question Link: https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int minn = nums[i];
            int maxx = nums[i];
            for (int j = i; j < len; j++) {
                minn = min(nums[j], minn);
                maxx = max(nums[j], maxx);
                result += maxx - minn;
            }   
        }
        
        return result;
    }
};