// Question Link: https://leetcode.com/problems/sorting-the-sentence/

class Solution {
public:
    string sortSentence(string s) {
        vector<string> wordsByNum(10);
        istringstream iss(s);
        string word = "";
        while (iss >> word) {
            int slot = word.back() - '0';
            word.pop_back();
            wordsByNum[slot] = word;
        }
        string result = "";
        for (string &word : wordsByNum) {
            result += (word != "") ? (word + " ") : "";
        }
        result.pop_back();
        return result;
    }
};