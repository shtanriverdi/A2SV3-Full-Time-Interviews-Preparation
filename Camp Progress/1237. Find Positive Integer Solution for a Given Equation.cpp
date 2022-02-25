// Question Link: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        for (int x = 1; x <= 1000; x++) {
            vector<int> pair = binarySearch(customfunction, x, z);
            if (pair[0] != -1) {
                result.push_back(pair);
            }
        }
        
        return result;
    }
    
    vector<int> binarySearch(CustomFunction& f, int x, int z) {
        int l = 1, r = 1000, midY, possibleAnswer;
        while (l <= r) {
            midY = l + (r - l) / 2;
            possibleAnswer = f.f(x, midY);
            if (possibleAnswer == z) {
                return { x, midY };
            }
            else if (possibleAnswer > z) {
                r = midY - 1;
            }
            else {
                l = midY + 1;   
            }
        }
        
        return { -1, -1 };
    }
};