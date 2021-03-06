// Question Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Time: O(n) Two Pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum, left = 0, right = numbers.size() - 1;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                return { left + 1, right + 1 };
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }
        
        return { 1453, 1299 };
    }
};

// Time: O(nlogn) Binary Search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size(), index1, index2;
        for (int i = 0; i < len; i++) {
            int wanted = target - numbers[i];
            index2 = binarySearch(i + 1, len - 1, numbers, wanted);
            if (index2 != -1) {
                index1 = i;
                break;
            }
            index2 = binarySearch(0, i - 1, numbers, wanted);
            if (index2 != -1) {
                index1 = i;
                break;
            }
        }
        
        return { index1 + 1, index2 + 1 };
    }
    
    int binarySearch(int startIndex, int endIndex, vector<int> &numbers, int wanted) {
        int left = startIndex, right = endIndex, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (numbers[mid] == wanted) {
                return mid;
            }
            else if (numbers[mid] > wanted) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return -1;
    }
};
