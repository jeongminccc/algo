//
//  4485_녹색옷 입은애가 젤다지?.cpp
//  algo
//
//  Created by jm on 2020/09/10.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_N = 130;
const int INF = 1e9; // 절대 나올 수 없는 경로값
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int N, dist[MAX_N][MAX_N], map[MAX_N][MAX_N];
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

int Dijkstra(){
    priority_queue<pipii, vector<pipii>, greater<>> pq;
    pq.push({map[0][0], {0,0}});
    dist[0][0] = map[0][0];
    
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i=0; i<4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(dist[nx][ny] > cost + map[nx][ny]){
                    dist[nx][ny] = cost + map[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    
    return dist[N-1][N-1];
}

int main(){
    int t=0;
    while(++t){
        cin >> N;
        if(N == 0) break;
        
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                dist[i][j] = INF;
        
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                cin >> map[i][j];
        
        cout << "Problem " << t << ": " << Dijkstra() << '\n';
    }
    return 0;
}
