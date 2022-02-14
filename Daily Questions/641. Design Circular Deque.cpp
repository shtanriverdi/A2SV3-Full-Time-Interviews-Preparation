// Question Link: https://leetcode.com/problems/design-circular-deque

class MyCircularDeque {
private:
    deque<int> deque;
    int limit;
public:
    MyCircularDeque(int k) {
        limit = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        deque.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        deque.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        deque.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        deque.pop_back();
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return deque.front();
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return deque.back();
    }
    
    bool isEmpty() {
        return deque.empty();
    }
    
    bool isFull() {
        return deque.size() == limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */