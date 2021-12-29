// Question Link: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int &num : nums) {
            countMap[num]++;
        }
        
        int times = nums.size() / 3;
        vector<int> result;
        for (auto &it : countMap) {
            if (it.second > times) {
                result.push_back(it.first);
            }
            if (result.size() == 2) {
                break;
            }
        }
        
        return result;
    }
};