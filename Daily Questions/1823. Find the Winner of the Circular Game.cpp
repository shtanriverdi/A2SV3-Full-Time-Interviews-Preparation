// Question Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> players(n, 0);
        for (int i = 1; i <= n; i++) {
            players[i - 1] = i;
        }
        
        k--; // Make 0-indexed
        int startIdx = 0, offset, tillEnd, removeIdx;
        while (players.size() != 1) {
            offset = (k % players.size());
            removeIdx = startIdx + offset;
            if (removeIdx >= players.size()) {
                tillEnd = players.size() - startIdx;
                removeIdx = offset - tillEnd;
            }
            players.erase(begin(players) + removeIdx);
            startIdx = getNextStartIndex(players, removeIdx);
        }
        
        return players.back();
    }
    
    int getNextStartIndex(vector<int> &players, int &lastRemovedIdx) {
        if (lastRemovedIdx < players.size()) {
            return lastRemovedIdx;
        }
        else {
            return 0;
        }
    }
};