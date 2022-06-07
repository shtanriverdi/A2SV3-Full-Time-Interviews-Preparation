// Question Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<vector<int>> numCounts;
        int pointer1 = 0, pointer2 = 0;
        
        while (pointer1 < m && pointer2 < n) {
            if (nums1[pointer1] < nums2[pointer2]) {
                appendToList(nums1[pointer1], numCounts, 1);
                pointer1++;
            }
            else if (nums1[pointer1] == nums2[pointer2]) {
                appendToList(nums1[pointer1], numCounts, 2);
                pointer1++;
                pointer2++;
            }
            else if (nums2[pointer2] < nums1[pointer1]) {
                appendToList(nums2[pointer2], numCounts, 1);
                pointer2++;
            }
        }
        
        appendRemaningItems(pointer1, nums1, m, numCounts);
        appendRemaningItems(pointer2, nums2, n, numCounts);
        
        pointer1 = 0;
        for (vector<int> &numCount : numCounts) {
            while (numCount[1] > 0) {
                nums1[pointer1] = numCount[0];
                numCount[1]--;
                pointer1++;
            }
        }   
    }
    
    void appendToList(int &item, vector<vector<int>> &numCounts, int amount) {
        if (numCounts.size() > 0 && numCounts.back()[0] == item) {
            numCounts.back()[1] += amount;
        }
        else {
            numCounts.push_back({ item, amount });
        }
    }
    
    void appendRemaningItems(int &pointer, vector<int> &list, int &len, vector<vector<int>> &numCounts) {
        while (pointer < len) {
            appendToList(list[pointer], numCounts, 1);
            pointer++;
        }
    }
};