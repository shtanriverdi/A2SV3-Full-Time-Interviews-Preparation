// Question Link: https://www.hackerrank.com/challenges/reduced-string/problem

// O(N) Stack Solution
string superReducedString(string &s) {
    stack<char> charStack;
    for (char c : s) {
        if (!charStack.empty() && charStack.top() == c) {
            charStack.pop();
        }
        else {
            charStack.push(c);
        }
    }
    
    string result = "";
    for (; !charStack.empty(); charStack.pop()) {
        result += charStack.top();
    }
    
    reverse(begin(result), end(result));
    return result == "" ? "Empty String" : result;
}

// Brute Force Solution
bool merge(vector<pair<char, int>> &charCntArr) {
    bool anyMerged = false;
    vector<pair<char, int>> mergedArr;
    
    if (charCntArr.empty() == false) {
        mergedArr.push_back( charCntArr[0] );
    }
    else {
        return anyMerged;
    }
    
    for (int i = 1; i < charCntArr.size(); i++) {
        if (charCntArr[i - 1].first == charCntArr[i].first) {
            mergedArr.back().second++;
            anyMerged = true;
        }
        else {
            mergedArr.push_back(charCntArr[i]);
        }
    }
    charCntArr = mergedArr;
    return anyMerged;
}

bool clean(vector<pair<char, int>> &charCntArr) {
    vector<pair<char, int>> removedArr;
    bool anyCleaned = false;
    for (pair<char, int> &pair : charCntArr) {
        if (pair.second % 2 == 0) {
            anyCleaned = true;
        }
        else {
            pair.second = (pair.second % 2);
            removedArr.push_back( pair );
        }
    }
    charCntArr = removedArr;
    return anyCleaned;
} 

string superReducedString(string &s) {
    vector<pair<char, int>> charCntArr;
    
    for (char c : s) {
        if (!charCntArr.empty() && c == charCntArr.back().first) {
            charCntArr.back().second++;
        }
        else {
            charCntArr.push_back({ c, 1 });
        }
    }
    
    bool isMerged = 1, isClean = 1;
    while ((isMerged || isClean) && !charCntArr.empty()) {
        isClean = clean(charCntArr);
        isMerged = merge(charCntArr);
    }
    
    string res = "";
    for (pair<char, int> &pair : charCntArr) {
        res += pair.first;
    }
    
    return (res == "" ? "Empty String" : res);
}