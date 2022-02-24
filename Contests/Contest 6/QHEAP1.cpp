// Question Link: https://www.hackerrank.com/contests/a2sv3-contest-6/challenges/qheap1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    set<int> minheap;
    while (Q-- > 0) {
        int query, v;
        cin >> query;
        // add v
        if (query == 1) {
            cin >> v;
            minheap.insert(v);
        }
        // remove v
        else if (query == 2) {
            cin >> v;
            minheap.erase(v);
        }
        // 3, print min
        else {
            cout << *minheap.begin() << endl;
        }
    }
    
    return 0;
}