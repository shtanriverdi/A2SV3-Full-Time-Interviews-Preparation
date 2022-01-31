// Question Link: https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoDecStack;
        unordered_map<int, int> numNextGreaterMap;
        for (int &num : nums2) {
            while (!monoDecStack.empty() && num > monoDecStack.top()) {
                numNextGreaterMap[monoDecStack.top()] = num;
                monoDecStack.pop();
            }
            monoDecStack.push(num);
        }
        for (int &num : nums1) {
            if (numNextGreaterMap.find(num) == numNextGreaterMap.end()) {
                num = -1;
            }
            else {
                num = numNextGreaterMap[num];
            }
        }
        
        return nums1;
    }
};