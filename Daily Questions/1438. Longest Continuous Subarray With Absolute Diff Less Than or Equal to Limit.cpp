// Question Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Monotonic Queue Solution O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int L = 0, R = 0, result = 0, len = nums.size();
        deque<int> maxDeque, minDeque;
        for (; R < len; R++) {
            updateQueues(minDeque, maxDeque, nums[R]);
            int minn = minDeque.front(); // Get min
            int maxx = maxDeque.front(); // Get max
            int diff = maxx - minn;
            // Update L pointer and Window
            if (diff > limit) {
                if (nums[L] == minDeque.front()) {
                    minDeque.pop_front();
                }
                if (nums[L] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                L++;
            }
            int windowLen = R - L + 1;
            result = max(windowLen, result);
        }
        return result;
    }
    
    void updateQueues(deque<int> &minDeque, deque<int> &maxDeque, int val) {
        // Update min deque
        while (!minDeque.empty() && val < minDeque.back()) {
            minDeque.pop_back();
        }
        minDeque.push_back(val);
        // Update max deque
        while (!maxDeque.empty() && val > maxDeque.back()) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(val);
    }
};

// Map Solution O(NlogN)
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
