// Question Link: https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
private:
    stack<int> temp, qStack;
public:
    void push(int x) {
        for (; !qStack.empty(); qStack.pop()) {
            temp.push(qStack.top());
        }
        qStack.push(x);
        for (; !temp.empty(); temp.pop()) {
            qStack.push(temp.top());
        }
    }
    
    int pop() {
        int elem = peek();
        qStack.pop();
        return elem;
    }
    
    int peek() {
        return qStack.top();
    }
    
    bool empty() {
        return qStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */