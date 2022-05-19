// Question Link: https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        int len = tiles.size();

        vector<int> prefixSum(len, 0);
        prefixSum[0] = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < len; i++) {
            prefixSum[i] += prefixSum[i - 1] + tiles[i][1] - tiles[i][0] + 1;
        }

        int maxCoveredTiles = 1;
        for (int i = 0; i < len; i++) {
            int tileStartIndex = tiles[i][0];
            int carpetEndIndex = tileStartIndex + carpetLen - 1;

            int tipOfCarpetIndex = binarySearch(tiles, i, len, carpetEndIndex);
            
            int currentMaxCoveredTiles = prefixSum[tipOfCarpetIndex] - (i - 1 >= 0 ? prefixSum[i - 1] : 0);
            
            int tileEndIndex = tiles[tipOfCarpetIndex][1];
            int uncoveredPart = tileEndIndex - carpetEndIndex;
            
            currentMaxCoveredTiles -= (uncoveredPart > 0) ? uncoveredPart : 0;
            
            maxCoveredTiles = max(maxCoveredTiles, currentMaxCoveredTiles);
        }
        
        return maxCoveredTiles;
    }
    
    int binarySearch(vector<vector<int>> &tiles, int startIndex, int &len, int carpetEndIndex) {
        int midIndex;
        int leftIndex = startIndex;
        int rightIndex = len - 1;
        
        while (leftIndex <= rightIndex) {
            midIndex = (leftIndex + rightIndex) / 2;
            int tileStartIndex = tiles[midIndex][0];
            int tileEndIndex = tiles[midIndex][1];
            
            if (carpetEndIndex >= tileStartIndex && carpetEndIndex <= tileEndIndex) {
                break;
            }
            else if (carpetEndIndex < tileStartIndex) {
                rightIndex = midIndex - 1;
            }
            else if (carpetEndIndex > tileEndIndex) {
                leftIndex = midIndex + 1;
            }
        }
        
        if (rightIndex < leftIndex) {
            midIndex = rightIndex;
        }
        
        return midIndex;
    }
};