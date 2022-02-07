// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-3/challenges/sherlock-and-squares

int nextSquare(int a, int b) {
    for (int n = a; n <= b; n++) {
        int val = sqrt(n);
        if (val * val == n) {
            return n;
        }
    }
    return -1;
}


int prevSquare(int b, int a) {
    for (int n = b; n >= a; n--) {
        int val = sqrt(n);
        if (val * val == n) {
            return n;
        }
    }
    return -1;
}

int squares(int a, int b) {
    int count = 0;
    int nextSqrtVal = nextSquare(a, b);
    int prevSqrtVal = prevSquare(b, a);
    
    if (nextSqrtVal == -1 && prevSqrtVal == -1) {
        return count;
    }
    
    int l = sqrt(nextSqrtVal);
    int r = sqrt(prevSqrtVal);
    
    return r - l + 1;
}