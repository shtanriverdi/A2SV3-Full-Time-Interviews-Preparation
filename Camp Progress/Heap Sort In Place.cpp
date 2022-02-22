// Question Link: https://practice.geeksforgeeks.org/problems/heap-sort/1/#

// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

/*
Heap Implementation

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

You can multiply the numbers with -1 and then get the max heap 
*/

class Solution {
public:
    void insert(int arr[], int n, int i) {
        heapUp(arr, n, i);
    }
    
    void remove(int arr[], int n, int i) {
        swap(arr[i], arr[n - 1]);
        heapify(arr, n - 1, i);
    }
    
    void update(int arr[], int n, int i, int element) {
        arr[i] = element;
        heapify(arr, n, i);
    }
    
    void heapUp(int arr[], int n, int i) {
        int parentIndex = parent(n, i);
        while (parentIndex != -1 && arr[i] > arr[parentIndex]) {
            swap(arr[i], arr[parentIndex]);
            i = parentIndex;
            parentIndex = parent(n, i);
        }
    }
    
    void heapDown(int arr[], int n, int i) {
        int leftChildIndex, rightChildIndex;
        while (i != -1) {
            rightChildIndex = rightChild(n, i);
            leftChildIndex = leftChild(n, i);
            
            if (rightChildIndex != -1 && arr[rightChildIndex] > arr[leftChildIndex] 
            && arr[rightChildIndex] > arr[i]) {
                swap(arr[rightChildIndex], arr[i]);
                i = rightChildIndex;
            }
            else if (leftChildIndex != -1 && arr[leftChildIndex] > arr[i]) {
                swap(arr[leftChildIndex], arr[i]);
                i = leftChildIndex;
            }
            else {
                break;
            }
        }
    }

    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        heapUp(arr, n, i);
        heapDown(arr, n, i);
    }
    
    int getMax(int arr[]) {
        return arr[0];
    }
    
    int leftChild(int n, int i) {
        int leftChildIndex = (i * 2) + 1;
        if (leftChildIndex >= n) {
            return -1;
        }
        return leftChildIndex;
    }
    
    int rightChild(int n, int i) {
        int rightChildIndex = (i * 2) + 2;
        if (rightChildIndex >= n) {
            return -1;
        }
        return rightChildIndex;
    }
    
    int parent(int n, int i) {
        if (i == 0) {
            return -1;
        }
        int parentIndex = (i - 1) / 2;
        return parentIndex;
    }

    // Function to build a Heap from array.
    void buildHeap(int arr[], int n) { 
        for (int i = 0; i < n; i++) {
            heapUp(arr, n, i);
        }
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[i], arr[0]);
            heapDown(arr, i, 0);
        }
    }
};

// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends