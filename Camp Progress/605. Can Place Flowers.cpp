// Question Link: https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for (int i = 0; i < N; i++) {
            bool l = (i - 1 >= 0) ? (flowerbed[i - 1] == 0 ? true : false) : true;
            bool r = (i + 1 < N) ? (flowerbed[i + 1] == 0 ? true : false) : true;
            if (flowerbed[i] == 0 && l && r) {
                flowerbed[i] = 1;
                n--;
            }
        }
        
        return n <= 0;
    }
};