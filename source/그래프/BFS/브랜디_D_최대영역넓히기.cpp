//
//  브랜디_D.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[101][101];
bool check[101][101];
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};


bool check_next(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

int flow(int startX, int startY){
    queue<pair<pair<int,int>, int>> q;
    q.push({make_pair(startX, startY), 0});
    check[startX][startY] = true;
    int ret = 1;
    
    while(!q.empty()){
        startX = q.front().first.first;
        startY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt == M) continue;
        
        for(int i=0; i<4; i++){
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];
            if(check_next(nextX, nextY) && arr[nextX][nextY] != 1 && !check[nextX][nextY]){
                q.push({{nextX,nextY},cnt+1});
                check[nextX][nextY] = true;
                ret++;
            }
        }
    }
    
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            memset(check, false, sizeof(check));
            if(arr[i][j] != 1)
                ans = max(ans , flow(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
