//
//  16991_외판원 순회3.cpp
//  algo
//
//  Created by jm on 2020/09/08.
//  Copyright © 2020 jm. All rights reserved.
//
//
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int INF = 1e9;

int N, K;
double space[16][16], dp[16][1<<16];
int pos[16][2];

double TSP(int current, int visited){
    double& ret = dp[current][visited];
    if(ret != 0) return ret;
    
    if(visited == (1<<N)-1){ // 모든 마을을 방문한 경우
        if(space[current][0] != 0) return space[current][0];
        return INF;
    }
    
    ret = INF;
    for(int i=0; i<N; ++i){
        if(visited & (1<<i) || space[current][i] == 0) continue;
        
        ret = min(ret, TSP(i, visited | (1<<i)) + space[current][i]);
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i=0; i<N; ++i) cin >> pos[i][0] >> pos[i][1];
    
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            space[i][j] = sqrt( pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2) );
    
    memset(dp, 0, sizeof(dp));
//    cout << dp[0][0] << endl;
    
    cout << fixed;
    cout.precision(6);
    cout << TSP(0,1);
    return 0;
}
