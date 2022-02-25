// Question Link: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    void addNum(int num) {
        maxHeap.push(num);
        if (maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top() * 1.0;
    }
};