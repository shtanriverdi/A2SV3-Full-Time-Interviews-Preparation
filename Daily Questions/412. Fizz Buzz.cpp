// Question Link: https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string numStr;
        for (int num = 1; num <= n; num++) {
            if (num % 3 == 0 && num % 5 == 0) {
                numStr = "FizzBuzz";
            }
            else if (num % 3 == 0) {
                numStr = "Fizz";
            }
            else if (num % 5 == 0) {
                numStr = "Buzz";
            }
            else {
                numStr = to_string(num);
            }
            result.push_back(numStr);
        }
        return result;
    }
};