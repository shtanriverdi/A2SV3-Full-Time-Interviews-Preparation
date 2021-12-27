// Question Link: https://www.hackerrank.com/challenges/insertionsort1/problem

void print(vector<int> &arr) {
    for (int &n : arr) {
        cout << n << " ";
    }
    cout << endl;
}

void insertionSort1(int n, vector<int> &arr) {
    int unsortedNum = arr.back();
    int index = n - 1;
    bool slotFound = false;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > unsortedNum) {
            arr[index] = arr[i];
            index--;
            print(arr);
        }
        else {
            arr[index] = unsortedNum;
            print(arr);
            slotFound = true;
            break;
        }
    }
    if (slotFound == false) {
        arr[index] = unsortedNum;
        print(arr);
    }
}