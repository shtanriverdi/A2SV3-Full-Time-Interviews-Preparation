// Question Link: https://practice.geeksforgeeks.org/problems/heap-sort/1/

/*
Please implement the following functions, we will manually check your implementation:
1- insert(element)
2- remove(index)
3- update(index)
4- int getMin()
5- heapSort(array)

Please implement and use the following helper functions:
1- leftChild(index)
2- rightChild(index)
3- parent(index)
*/

class Solution {
private:
    vector<int> minHeap;

public:
    void insert(int element) {
        minHeap.push_back(element);
        int insertedIndex = minHeap.size() - 1;
        int parentIndex = parent(insertedIndex);
        heapUp(insertedIndex, parentIndex);
    }

    void heapify(int index) {
        if (!isEmpty()) {
            int parentIndex = parent(index);
            int leftChildIndex = leftChild(index);
            int rightChildIndex = rightChild(index);
            
            // Check parent, and go up
            if (isValidIndex(parentIndex) && minHeap[index] < minHeap[parentIndex]) {
                heapUp(index, parentIndex);
                return;
            }
            
            // Check children and go down
            bool isLeftChildIndexValid = isValidIndex(leftChildIndex);
            bool isRightChildIndexValid = isValidIndex(rightChildIndex);
            if (isLeftChildIndexValid && isRightChildIndexValid) {
                int smallerChildIndex = minHeap[leftChildIndex] < minHeap[rightChildIndex] ?
                    leftChildIndex : rightChildIndex;
                // Go to smaller child
                heapDown(index, smallerChildIndex);
                return;
            }
            if (isLeftChildIndexValid) {
                heapDown(index, leftChildIndex);
            }
            else {
                heapDown(index, rightChildIndex);
            }
        }
    }
    
    void heapUp(int index, int parentIndex) {
        while (index > 0 && isValidIndex(parentIndex) && minHeap[index] < minHeap[parentIndex]) {
            swap(minHeap[index], minHeap[parentIndex]);
            index = parentIndex;
            parentIndex = parent(index);
        }
    }
    
    void heapDown(int index, int childIndex) {
        while (isValidIndex(childIndex) && minHeap[index] > minHeap[childIndex]) {
            swap(minHeap[index], minHeap[childIndex]);
            index = childIndex;
            // Update childrenIndex
            int leftChildIndex = leftChild(index);
            int rightChildIndex = rightChild(index);
            // Check children and go down
            bool isLeftChildIndexValid = isValidIndex(leftChildIndex);
            bool isRightChildIndexValid = isValidIndex(rightChildIndex);
            if (isLeftChildIndexValid && isRightChildIndexValid) {
                childIndex = minHeap[leftChildIndex] < minHeap[rightChildIndex] ?
                    leftChildIndex : rightChildIndex;
            }
            else if (isLeftChildIndexValid) {
                childIndex = leftChildIndex;
            }
            else {
                childIndex = rightChildIndex;
            }
        }
    }

    void remove(int index) {
        if (!isEmpty()) {
            minHeap[index] = minHeap.back();
            minHeap.pop_back();
            heapify(index);
        }
    }
    
    void update(int index, int newElement) {
        minHeap[index] = newElement;
        heapify(index);
    }
    
    int getMin() {
        return !isEmpty() ? minHeap[0] : -1;
    }

    int leftChild(int index) {
        int leftChildIndex = (index * 2) + 1;
        if (!isValidIndex(leftChildIndex)) {
            return -1;
        }
        return leftChildIndex;
    }
    
    int rightChild(int index) {
        int rightChildIndex = (index * 2) + 2;
        if (!isValidIndex(rightChildIndex)) {
            return -1;
        }
        return rightChildIndex;
    }
    
    int parent(int index) {
        if (index == 0) {
            return -1;
        }
        return floor((index - 1) / 2);
    }
    
    bool isEmpty() {
        return minHeap.empty();
    }
    
    bool isValidIndex(int index) {
        int size = minHeap.size();
        return index >= 0 && index < size;
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        Solution minHeap;
        for (int i = 0; i < n; i++) {
            minHeap.insert(arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = minHeap.getMin();
            minHeap.remove(0);
        }
    }
};