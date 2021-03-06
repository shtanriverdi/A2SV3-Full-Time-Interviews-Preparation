// Question Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // comp(x,y) should return true 
        // if x is supposed to be placed before y in the resulting vector
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            if (a.size() < b.size()) {
                return true;
            }
            else if (a.size() == b.size()) {
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] < b[i]) {
                        return true;
                    }
                    else if (a[i] > b[i]) {
                        return false;
                    }
                }
            }
            return false;
        });
        
        return nums[nums.size() - k];
    }
};