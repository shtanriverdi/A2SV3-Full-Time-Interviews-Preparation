// Question Link: https://practice.geeksforgeeks.org/problems/selection-sort/1

class Solution
{
    public:
    int select(int arr[], int i) {
        // code here such that selectionSort() sorts arr[]
    }
     
    void selectionSort(int arr[], int n) {
        int minIdx = 0;
        for (int i = 0; i < n - 1; i++) {
            minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[minIdx], arr[i]);
        }
    }
};