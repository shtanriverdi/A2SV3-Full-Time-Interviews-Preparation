// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-6/challenges/jesse-and-cookies

int cookies(int k, vector<int> &A) {
    priority_queue<int> minHeap;
    for (int &candy : A) {
        minHeap.push(-1 * candy);
    }
    
    if ( (-1 *minHeap.top()) >= k ) {
        return 0;
    }
    
    int minOperations = 0;
    while (minHeap.size() > 1 && (-1 * minHeap.top()) < k) {
        
        int less = -1 * minHeap.top();
        minHeap.pop();
        
        int secondLess = -1 * minHeap.top();
        minHeap.pop();
        
        minHeap.push(-1 * (less + (secondLess * 2)));
        minOperations++;
    }
    
    if (minOperations == 0 || (-1 * minHeap.top()) < k) {
        return -1;
    }
    
    return minOperations;
}