// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-3/challenges/climbing-the-leaderboard/

// O(N)
vector<int> climbingLeaderboard(vector<int> &ranked, vector<int> &player) {
    stack<int> monoDecreasingStack;
    monoDecreasingStack.push(ranked.front());
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] != monoDecreasingStack.top()) {
            monoDecreasingStack.push(ranked[i]);
        }
    }
    
    vector<int> result;
    for (int &p : player) {
        while (!monoDecreasingStack.empty() and p >= monoDecreasingStack.top()) {
            monoDecreasingStack.pop();
        }
        monoDecreasingStack.push(p);
        int rank = monoDecreasingStack.size();
        result.push_back(rank);
    }
    
    return result;
}


// O(NLOGN)
vector<int> climbingLeaderboard(vector<int> &ranked, vector<int> &player) {
    int lenPlayer = player.size();
    int lenRank = ranked.size();
    unordered_map<int, int> leaderboardMap;
    int rank = 1;
    for (int &r : ranked) {
        if (leaderboardMap.find(r) == leaderboardMap.end()) {
            leaderboardMap[r] = rank;
            rank++;
        }
    }
    
    reverse(ranked.begin(), ranked.end());
    vector<int> result;
    for (int i = 0; i < lenPlayer; i++) {
        auto which = lower_bound(ranked.begin(), ranked.end(), player[i]);
        int foundScore = *which;
        int playerScore = player[i];
        int index = which - ranked.begin();
        if (foundScore == playerScore) {
            result.push_back(leaderboardMap[foundScore]);
        }
        else if (playerScore < foundScore) {
            result.push_back(leaderboardMap[foundScore] + 1);
        }
        else if (index == lenRank) {
            result.push_back(1);
        }
    }
    
    return result;
}