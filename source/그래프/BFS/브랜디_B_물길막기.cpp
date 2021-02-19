//
//  브랜디_B.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int N, M, goal_X, goal_Y, goal_distance;
int arr[51][51];
bool check[51][51];
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

bool check_path(int x, int y){
    if(2*(N-1) - (x+y) < goal_distance) return true;
    return false;
}

bool check_next(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

int flow(int startX, int startY){
    queue<pair<pair<int,int>, int>> q;
    q.push({{startX, startY},0});
    check[startX][startY] = true;
    int ret = 1;
    
    while(!q.empty()){
        startX = q.front().first.first;
        startY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = startX + dx[i];
            int nextY = startY + dy[i];
            if(nextX == goal_X && nextY == goal_Y) goal_distance = min(cnt+1, goal_distance);
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
    cin >> N;
    int numOfWall = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) numOfWall++;
        }
    }
    
    int ans=0, flowNum=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            memset(check, false, sizeof(check));
            if( (i==0 && j==0) || (i==N-1 && j==N-1) ) continue;
            if(arr[i][j] != 1){
                arr[i][j] = 1;
                goal_X = i; goal_Y = j; goal_distance=1e9;
                flowNum = flow(0, 0);
                if(ans < N*N - flowNum - numOfWall - 1 && check_path(i, j)){
                    ans = N*N - flowNum - numOfWall - 1;
                }
                arr[i][j] = 0;
            }
        }
    }
    flowNum = flow(0, 0);
    if(ans < N*N - flowNum - numOfWall - 1){
        ans = N*N - flowNum - numOfWall - 1;
    }
    
    cout << ans << endl;
    return 0;
}

