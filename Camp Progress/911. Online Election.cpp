// Question Link: https://leetcode.com/problems/online-election/

class TopVotedCandidate {
private:
    int len;
    vector<int> P, T, maxVotedPersonAtTimeT;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        len = persons.size();
        P = persons;
        T = times;
        maxVotedPersonAtTimeT.resize(len);
        
        unordered_map<int, int> personVoteCountsMap;
        personVoteCountsMap[persons[0]]++;
        
        int maxVotedPerson = persons[0];
        maxVotedPersonAtTimeT[0] = maxVotedPerson;
        
        for (int t = 1; t < len; t++) {
            personVoteCountsMap[persons[t]]++;
            if (personVoteCountsMap[persons[t]] >= personVoteCountsMap[maxVotedPerson]) {
                maxVotedPerson = persons[t];
            }
            maxVotedPersonAtTimeT[t] = maxVotedPerson;
        }
    }
    
    int q(int t) {
        int maxVotedPersonIndexAtTimeT = binarySearch(t);
        return maxVotedPersonAtTimeT[maxVotedPersonIndexAtTimeT];
    }
    
    int binarySearch(int t) {
        int l = 0, r = len - 1, m, best;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (T[m] > t) {
                r = m - 1;
            }
            else {
                best = m;
                l = m + 1;
            }
        }
        
        return best;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */