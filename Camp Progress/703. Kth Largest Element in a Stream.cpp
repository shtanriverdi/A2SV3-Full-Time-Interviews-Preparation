// Question Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:
    priority_queue<int> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int &num : nums) {
            minHeap.push(-1 * num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(-1 * val);
        if (minHeap.size() > K) {
            minHeap.pop();
        }
        return minHeap.top() * -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */