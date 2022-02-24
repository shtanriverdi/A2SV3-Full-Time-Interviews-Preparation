// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-6/challenges/find-the-running-median
priority_queue<double> minn, maxx;

void addHeap(double n) {
    maxx.push(n);
    if (!minn.empty() && maxx.top() > (-1 * minn.top())) {
        minn.push(-1 * maxx.top());
        maxx.pop();
        maxx.push(-1 * minn.top());
        minn.pop();
    }
    if (maxx.size() - minn.size() > 1) {
        minn.push(-1 * maxx.top());
        maxx.pop();
    }
}

double getMedian() {
    if (minn.size() == maxx.size()) {
        return (((-1.0 * minn.top()) * 1.0) + (maxx.top()) * 1.0) / 2.0;
    }
    return maxx.top();
}

vector<double> runningMedian(vector<int> &a) {
    vector<double> result;
    for (int &n : a) {
        double nn = 1.0;
        nn *= n;
        addHeap(nn);
        double res = (double)getMedian() * 1.0;
        result.push_back(res * 1.0);
    }
    return result;
}