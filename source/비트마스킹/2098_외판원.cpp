//
//  2098_외판원.cpp
//  algo
//
//  Created by jm on 2020/09/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int INF = 1e9;

int N;
int tsp[16][16], dp[16][1<<16];

int TSP(int current, int visited){
    int& ret = dp[current][visited];
    if(ret != -1) return ret;
    
    if(visited == (1<<N)-1){ // 모든 마을을 방문한 경우
        if(tsp[current][0] != 0) return tsp[current][0];
        return INF;
    }
    
    ret = INF;
    for(int i=0; i<N; ++i){
        if(visited & (1<<i) || tsp[current][i] == 0) continue;
        
        ret = min(ret, TSP(i, visited | (1<<i)) + tsp[current][i]);
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> tsp[i][j];
    
    memset(dp, -1, sizeof(dp));
    cout << TSP(0,1);
    return 0;
}
