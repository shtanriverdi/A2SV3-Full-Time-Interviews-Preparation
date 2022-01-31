// Question Link: https://leetcode.com/problems/max-consecutive-ones-iii/

// Two Pointers Solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0, L = 0;
        for (int R = 0; R < nums.size(); R++) {
            if (nums[R] == 0) {
                if (k > 0) {
                    k--;
                }
                else {
                    popFrontZero(L, R, nums);
                }
            }
            int windowSize = R - L + 1;
            result = max(result, windowSize);
        }
        
        return result;
    }
    
    void popFrontZero(int &L, int &R, vector<int> &nums) {
        while (L <= R) {
            int val = nums[L];
            L++;
            if (val == 0) {
                break;
            }
        }
    }
};

// Deque Solution
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0, windowSize;
        deque<int> window;
        for (int &num : nums) {
            window.push_back(num);
            if (num == 0) {
                if (k > 0) {
                    k--;
                }
                else {
                    popFrontZero(window);
                }
            }
            windowSize = window.size();
            result = max(result, windowSize);
        }
        
        return result;
    }
    
    void popFrontZero(deque<int> &window) {
        while (!window.empty()) {
            int front = window.front();
            window.pop_front();
            if (front == 0) {
                break;
            }
        }
    }
};