// Question Link: https://www.hackerrank.com/challenges/counting-valleys/problem

int countingValleys(int steps, string &path) {
    int valleyCount = 0;
    for (int i = 0, sum = 0; i < steps; i++) {
        if (path[i] == 'U') { // +
            sum++;
            valleyCount += (sum == 0);
        }
        else { // -
            sum--;
        }
    }
    return valleyCount;
}