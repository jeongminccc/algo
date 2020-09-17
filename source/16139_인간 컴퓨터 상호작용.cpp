//
//  16139_인간 컴퓨터 상호작용.cpp
//  algo
//
//  Created by jm on 2020/09/16.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 int N, psum[200001][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    for(int i=1; i<=s.size(); ++i){
        for(int j=0; j<26; ++j)
            psum[i][j] = psum[i-1][j];
        
        psum[i][s[i-1] - 'a']++;
    }
    cin >> N;
    
    for(int i=0; i<N; ++i){
        char c;
        int from, to;
        cin >> c >> from >> to;
        
        cout << psum[to + 1][c - 'a'] - psum[from][c - 'a'] << " "; // 입력 a 0 5
        cout << "\n";
    }
    
    return 0;
}

