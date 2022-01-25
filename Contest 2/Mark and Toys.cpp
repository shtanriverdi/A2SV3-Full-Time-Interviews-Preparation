// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/mark-and-toys/

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */

int maximumToys(vector<int> prices, int k) {
    sort(begin(prices), end(prices));
    int count = 0;
    for (int &price : prices) {
        if (k >= price) {
            k -= price;
            count++;
        }
        else {
            break;
        }
    }
    return count;
}