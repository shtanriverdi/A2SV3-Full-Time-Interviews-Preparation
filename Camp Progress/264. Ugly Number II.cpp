// Question Link: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long> minHeap;
        minHeap.push(-1 * 1); // { number, nth }
        int nth = 0;
        long val = 1;
        while (!minHeap.empty() && nth < n) {
            val = -1 * minHeap.top();
            minHeap.pop();
            while (!minHeap.empty() && val == (-1 * minHeap.top())) {
                minHeap.pop();
            }
            nth++;
            minHeap.push(-1 * val * 2);
            minHeap.push(-1 * val * 3);
            minHeap.push(-1 * val * 5);
        }
        
        return val;
    }
};