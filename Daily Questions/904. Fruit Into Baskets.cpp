// Question Link: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size(), L = 0, R = 0, result = 0;
        unordered_map<int, int> fruitCntMap;
        for (; R < len; R++) {
            fruitCntMap[fruits[R]]++;
            while (fruitCntMap.size() > 2) {
                fruitCntMap[fruits[L]]--;
                if (fruitCntMap[fruits[L]] == 0) {
                    fruitCntMap.erase(fruits[L]);
                }
                L++;
            }
            result = max(result, R - L + 1);
        } 
        
        return result;
    }
};