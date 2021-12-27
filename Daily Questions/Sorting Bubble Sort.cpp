// Question Link: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

void countSwaps(vector<int> &a) {
    int n = a.size(), swapCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swapCount++;
                swap(a[j], a[j + 1]);
            }
        }
    }
    cout << "Array is sorted in " + to_string(swapCount) + " swaps." << endl;
    cout << "First Element: " << a.front() << endl;
    cout << "Last Element: " << a.back() << endl;
}