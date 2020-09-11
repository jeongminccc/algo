//
//  1327_소트게임.cpp
//  algo
//
//  Created by jm on 2020/09/08.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N, K;
string s = "";

int foo(){
    queue<pair<string, int>> q;
    q.push({s, 0});
    map<string, bool> visited;
    string ans = s;
    sort(ans.begin(), ans.end());
    
    while(!q.empty()){
        string isCorrect = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(isCorrect == ans) return cnt;
        
        if(visited.find(isCorrect) == visited.end()){
            visited[isCorrect] = true;
            
            for(int i=0; i<=N-K; ++i){
                string temp = isCorrect.substr(i, K);
                reverse(temp.begin(), temp.end());
                q.push({isCorrect.substr(0, i) + temp + isCorrect.substr(i + K, isCorrect.size()), cnt+1});
            }
        }
    }
    return -1;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; ++i){
        char input; cin >> input;
        s += input;
    }
    
    cout << foo();
    return 0;
}
