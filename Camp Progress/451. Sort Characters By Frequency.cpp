// Question Link: https://leetcode.com/problems/top-k-frequent-words

// O(NlogK)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCountMap;
        for (string &word : words) {
            wordCountMap[word]++;
        }
        
        auto cmp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first > b.first) {
                return true;
            }
            if (a.first == b.first && a.second < b.second) {
                return true;
            }
            return false;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> PQ(cmp);
        for (auto &it : wordCountMap) {
            PQ.push({ it.second, it.first });
            if (PQ.size() > k) {
                PQ.pop();
            }
        }
        
        vector<string> result;
        for (; !PQ.empty() && k > 0; PQ.pop(), k--) {
            result.push_back(PQ.top().second);
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};

// O(NlogK)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCountMap;
        for (string &word : words) {
            wordCountMap[word]++;
        }
        
        auto cmp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first < b.first) {
                return true;
            }
            if (a.first == b.first && a.second > b.second) {
                return true;
            }
            return false;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> PQ(cmp);
        for (auto &it : wordCountMap) {
            PQ.push({ it.second, it.first });
        }
        
        vector<string> result;
        for (; !PQ.empty() && k > 0; PQ.pop(), k--) {
            result.push_back(PQ.top().second);
        }
        
        return result;
    }
};