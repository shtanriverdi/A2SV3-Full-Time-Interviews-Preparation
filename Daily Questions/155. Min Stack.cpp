// Question Link: https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<vector<int>> minStack;
public:
    void push(int val) {
        minStack.push({ val, minStack.empty() ? val : min( getMin(), val ) });
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top()[0];
    }
    
    int getMin() {
        return minStack.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */