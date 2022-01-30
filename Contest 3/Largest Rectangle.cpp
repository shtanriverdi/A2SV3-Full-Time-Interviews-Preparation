// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/find-the-merge-point-of-two-joined-linked-lists/

long largestRectangle(vector<int> &h) {
    int len = h.size();
    stack<int> monoIncStackRight;
    vector<int> right(len, len);
    for (int i = 0; i < len; i++) {
        while (!monoIncStackRight.empty() && h[i] < h[monoIncStackRight.top()]) {
            right[monoIncStackRight.top()] = i;
            monoIncStackRight.pop();
        }
        monoIncStackRight.push(i);
    }
    
    stack<int> monoIncStackLeft;
    vector<int> left(len, -1);
    for (int i = len - 1; i >= 0; i--) {
        while (!monoIncStackLeft.empty() && h[i] < h[monoIncStackLeft.top()]) {
            left[monoIncStackLeft.top()] = i;
            monoIncStackLeft.pop();
        }
        monoIncStackLeft.push(i);
    }
    
    long result = 1;
    for (int i = 0; i < len; i++) {
        long curHeight = (right[i] - left[i] - 1) * h[i];
        if (curHeight > result) {
            result = curHeight;
        }
    }
    
    return result;
}