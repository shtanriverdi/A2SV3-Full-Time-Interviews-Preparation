// Question Link: https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
private:
    deque<vector<int>> requestDeq;
public:
    int ping(int t) {
        vector<int> newRequest = { t - 3000, t };
        while (!requestDeq.empty() && 
               (requestDeq.front()[1] < newRequest[0] ||
              requestDeq.front()[1] > newRequest[1])) {
            requestDeq.pop_front();
        }
        requestDeq.push_back( newRequest );
        return requestDeq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */