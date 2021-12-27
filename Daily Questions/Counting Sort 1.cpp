// Question Link: https://www.hackerrank.com/challenges/countingsort1/problem

vector<int> countingSort(vector<int> &arr) {
    vector<int> count(100, 0);
    for (int &n : arr) {
        count[n]++;
    }
    return count;
}