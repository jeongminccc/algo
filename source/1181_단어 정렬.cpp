//
//  1181_단어 정렬.cpp
//  algo
//
//  Created by jm on 2020/09/18.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto&a:s) cin >> a;
    
    sort(s.begin(), s.end(), [](const string& a, const string& b){
        return a.size() < b.size() ? true : b.size() < a.size() ? false : a < b;
    });
    s.erase(unique(s.begin(), s.end()), s.end());
    
    for(auto&a:s) cout << a << endl;
}
