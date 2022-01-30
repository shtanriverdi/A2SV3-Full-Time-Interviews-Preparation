// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-3/challenges/angry-children

int maxMin(int k, vector<int> &arr) {
    sort(begin(arr), end(arr));
    
    int len = arr.size();
    int l = 0, r = k - 1;
    int minfFairness = arr[r] - arr[l];
    int curFairness = arr[r] - arr[l];
    
    l++;
    r++;
    while (r < len) {
        curFairness = arr[r] - arr[l];
        minfFairness = min(curFairness, minfFairness);
        l++;
        r++;
    }
    
    return minfFairness;
}