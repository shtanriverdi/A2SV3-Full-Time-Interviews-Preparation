// Question Link: https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sortedNums;
        for (int &num : nums) {
            sortedNums.push_back(to_string(num));
        }
        
        sort(begin(sortedNums), end(sortedNums), [](const string &a, const string &b) {
            return (a + b) > (b + a);
        });
        
        string result = "";
        for (string &s : sortedNums) {
            result += s;
        }
        
        return (result[0] == '0') ? "0" : result;
    }
};