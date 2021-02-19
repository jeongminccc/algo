//
//  [BFS]5014_스타트링크.cpp
//  algo
//
//  Created by jm on 2020/09/09.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

int F, S, G, U, D; // 최고 층, 현재 층, 목표 층, 올라가는 단위, 내려가는 단위
bool visited[MAX + 1];

int bfs(){
    queue<int> q;
    q.push(S);
    visited[S] = true;
    
    int cnt=0;
    while(!q.empty()){
        int size = (int)q.size();
        
        for(int i=0; i<size; ++i){
            int pos = q.front();
            q.pop();
            if(pos == G) return cnt;
            if(pos + U <= G && !visited[pos+U]) {q.push(pos+U); visited[pos+U]=true;}
            if(pos - D >= 1 && !visited[pos-D]) {q.push(pos-D); visited[pos-D]=true;}
        }
        
        cnt++;
    }
    return -1;
}

int main(){
    cin >> F >> S >> G >> U >> D;

    int ans=0;
    if((ans = bfs()) == -1) cout << "use the stairs";
    else cout << ans;
    
    return 0;
}
