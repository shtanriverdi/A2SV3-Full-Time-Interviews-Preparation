// Question Link: https://www.hackerrank.com/contests/a2sv-3-contest-4/challenges/pairs

int pairs(int k, vector<int> &arr) {
    unordered_map<int, int> map;
    int result = 0;
    
    for (int &n : arr) {
        map[n]++;
    }
    
    for (int &n : arr) {
        int wanted = n - k;
        if (map.find(wanted) != map.end()) {
            result++;
        }
    }
    return result;
}