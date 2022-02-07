// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-2/challenges/recursive-digit-sum/

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

long long getValue(string n, int k) {
    long long int sum = 0;
    for (char c : n) {
        sum += c - '0';
    }
    return k * sum;
}
    
int superDigit(string n, int k) {
    long long int curVal = getValue(n, k);
    while (curVal > 10) {
        curVal = getValue(to_string(curVal), 1);
    }
    
    return curVal;
}