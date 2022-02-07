// Question Link: https://www.hackerrank.com/challenges/bear-and-steady-gene

long largestRectangle(vector<int> &h) {
bool isMapEnough(unordered_map<char, int> &neededWindowCountMap, unordered_map<char, int> &curWindowMap, int &need) {
    for (auto &it : neededWindowCountMap) {
        if (curWindowMap[it.first] < it.second) {
            return false;
        }
    }
    return true;
}

int steadyGene(string &gene) {
    unordered_map<char, int> geneCountMap;
    for (char c : gene) {
        geneCountMap[c]++;
    }
    
    int len = gene.size(), need = len / 4;
    unordered_map<char, int> neededWindowCountMap;
    for (auto &it : geneCountMap) {
        if (need - it.second < 0) {
            neededWindowCountMap.insert({ it.first, -1 * (need - it.second) });
        }
    }
    
    if (neededWindowCountMap.empty()) {
        return 0;
    }
    
    int L = 0, R = 0, result = 0;
    unordered_map<char, int> curWindowMap;
    for (; R < len && !isMapEnough(neededWindowCountMap, curWindowMap, need); R++) {
        curWindowMap[gene[R]]++;
        result = max(result, R - L + 1);
    }
    
    while (R < len) {
        if (isMapEnough(neededWindowCountMap, curWindowMap, need)) {
            curWindowMap[gene[L]]--;
            L++;
        }
        else {
            curWindowMap[gene[R]]++;
            result = min(result, R - L + 1);
            R++;
        }
    }
    
    return result;
}