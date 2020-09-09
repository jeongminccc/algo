//
//  [DFS]10026_적록색약.cpp
//  algo
//
//  Created by jm on 2020/09/09.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N;
char color[101][101];
bool check[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool isPossible(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void Dfs(int x, int y){
    check[x][y] = true;
    char cur = color[x][y];
    
    for(int i=0; i<4; ++i)
        if(isPossible(x+dx[i], y+dy[i]) && !check[x+dx[i]][y+dy[i]] && color[x+dx[i]][y+dy[i]] == cur)
            Dfs(x+dx[i], y+dy[i]);
}

void DfsForWeakness(int x, int y){
    check[x][y] = true;
    char cur = color[x][y];
    bool weakness = false;
    if(cur == 'R' || cur == 'G') weakness = true;
    
    
    for(int i=0; i<4; ++i){
        if(isPossible(x+dx[i], y+dy[i]) && !check[x+dx[i]][y+dy[i]]){
            if(weakness){
                if(color[x+dx[i]][y+dy[i]] == 'R' || color[x+dx[i]][y+dy[i]] == 'G')
                    DfsForWeakness(x+dx[i], y+dy[i]);
            }
            else
                if(color[x+dx[i]][y+dy[i]] == cur)  DfsForWeakness(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    cin >> N;
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> color[i][j];
    
    int ans=0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if(!check[i][j]){
                Dfs(i,j);
                ans++;
            }
    
    int ans_for_weakness=0;
    memset(check, false, sizeof(check));
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if(!check[i][j]){
                DfsForWeakness(i, j);
                ans_for_weakness++;
            }

    
    cout << ans << " " << ans_for_weakness;
    return 0;
}
