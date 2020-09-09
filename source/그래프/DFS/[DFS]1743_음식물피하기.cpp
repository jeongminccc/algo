//
//  [DFS]1743_음식물피하기.cpp
//  algo
//
//  Created by jm on 2020/09/09.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int aisle[101][101];
bool check[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool isPossible(int x, int y){
    return (x >= 1 && x <= N && y >= 1 && y <= M);
}

int dfs(int x, int y){
    int ret = 1;
    check[x][y] = true;
    
    for(int i=0; i<4; ++i)
        if(isPossible(x+dx[i], y+dy[i]) && !check[x+dx[i]][y+dy[i]] && aisle[x+dx[i]][y+dy[i]])
            ret += dfs(x+dx[i], y+dy[i]);
    
    return ret;
}

int main(){
    cin >> N >> M >> K;
    
    for(int i=0; i<K; ++i){
        int inputX, inputY;
        cin >> inputX >> inputY;
        aisle[inputX][inputY] = 1;
    }
    
    int ans=0;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            if(!check[i][j] && aisle[i][j])
                ans = max(ans, dfs(i,j));
    
    
    cout << ans;
    return 0;
}
