// Question Link: https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem

unsigned long long int minimumAverage(vector<vector<int>> &customers) {
    sort(begin(customers), end(customers));
    
    unsigned long long int totalWaitTime = 0, curTime = 0;
    priority_queue<vector<unsigned long long int>, vector<vector<unsigned long long int>>, greater<vector<unsigned long long int>>> pq; // { duration, orderTime }
    
    int index = 0, len = customers.size();
    while (index < len || !pq.empty()) {
        if (pq.empty()) {
            pq.push({ customers[index][1], customers[index][0] });
            if (curTime < customers[index][0]) {
                curTime = customers[index][0];
            }
            index++;
        }

        unsigned long long int orderTime = pq.top()[1];
        unsigned long long int duration = pq.top()[0];
        pq.pop();
        
        curTime += duration;
        totalWaitTime += curTime - orderTime;
        
        while (index < len && customers[index][0] <= curTime) {
            pq.push({ customers[index][1], customers[index][0] });
            index++;
        }
    }

    return floor(totalWaitTime / len);
}