// Question Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(begin(wordList), end(wordList)), seen = { beginWord };
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        
        queue<pair<string, int>> todo;
        todo.push({ beginWord, 1 });
        
        while (todo.size() > 0) {
            auto[ word, steps ] = todo.front();
            todo.pop();
            
            if (word == endWord) {
                return steps;
            }
            
            for (char &letter : word) {
                char prev = letter;
                for (char c = 'a'; c <= 'z'; c++) {
                    letter = c;
                    if (words.find(word) != words.end() && seen.find(word) == seen.end()) {
                        todo.push({ word, steps + 1 });
                        seen.insert( word );
                    }
                }
                letter = prev;
            }
        }
        
        return 0;
    }
};