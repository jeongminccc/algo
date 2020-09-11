//
//  1261_알고스팟.cpp
//  algo
//
//  Created by jm on 2020/09/10.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_N = 100;
const int INF = 1e9; // 절대 나올 수 없는 경로값
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int N,M, dist[MAX_N][MAX_N];
string map[MAX_N];
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

int Dijkstra(){
    priority_queue<pipii, vector<pipii>, greater<>> pq;
    pq.push({map[0][0] - '0', {0,0}});
    dist[0][0] = map[0][0] - '0';
    
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i=0; i<4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(dist[nx][ny] > cost + map[nx][ny] - '0'){
                    dist[nx][ny] = cost + map[nx][ny] - '0';
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    
    return dist[N-1][M-1];
}

int main(){
    
    cin >> M >> N;
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            dist[i][j] = INF;
    
    for(int i=0; i<N; ++i)
        cin >> map[i];
    
    cout << Dijkstra();
    
    return 0;
}
