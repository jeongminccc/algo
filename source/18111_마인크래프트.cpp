//
//  18111_마인크래프트.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main(){
    int n, m, b, map[501][501];
    cin >> n >> m >> b;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> map[i][j];
    
    int ans=INF, ansIndex=0;
    for(int l=0; l<=256; l++){
        int block = b;
        int time = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(map[i][j] > l){
                    time += (map[i][j] - l)*2;
                    block += (map[i][j] - l);
                }
                else{
                    time += (l - map[i][j]);
                    block -= (l - map[i][j]);
                }
            }
        }
        if(block < 0) time = INF;
        if(ans >= time){
            ans = time;
            ansIndex = l;
        }
    }
    
    cout << ans << " " << ansIndex;
}
