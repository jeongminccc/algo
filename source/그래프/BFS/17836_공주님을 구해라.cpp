//
//  17836_공주님을 구해라.cpp
//  algo
//
//  Created by jm on 2020/08/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
#define INF 985431231;

int N,M,T;
int board[101][101];
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0};

int bfs(int final_y, int final_x){
    bool check[101][101]={false};
    queue<pair<int,int>> q;
    q.push({0,0});
    int time=0;
    check[0][0] = true;
    
    while(!q.empty()){
        time++;
        int temp = q.size();
        
        for(int j=0; j<temp; j++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
//            cout << j <<" y : " << y << " x : " << x << endl;
            for(int i=0; i<4; i++){
                if( y+dir_y[i] >= 0 && y+dir_y[i] < N && x+dir_x[i] >= 0 && x+dir_x[i] < M && !check[y+dir_y[i]][x+dir_x[i]]){
                    if(y+dir_y[i] == final_y && x+dir_x[i] == final_x) return time;
                    if(board[y+dir_y[i]][x+dir_x[i]] != 1){
//                        cout << y+dir_y[i] << " " <<  x+dir_x[i] << endl;
                        q.push({ y+dir_y[i], x+dir_x[i] });
                        check[y+dir_y[i]][x+dir_x[i]] = true;
                    }
                }
            }
        }
    }
    return INF;
}

int main(){
    cin >> N >> M >> T;
    int sword_y=0, sword_x=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2){
                sword_x = j;
                sword_y = i;
            }
        }
    }
    
    int ans = min(bfs(sword_y, sword_x) + (N-sword_y-1) + (M-sword_x-1), bfs(N-1,M-1));
//    cout << bfs(sword_y, sword_x) + (N-sword_y-1) + (M-sword_x-1) << " " <<  bfs(N-1,M-1) << endl;
    
    if(ans > T) cout << "Fail" << endl;
    else cout << ans << endl;
    
    return 0;
}#include <bits/stdc++.h>

using namespace std;
#define INF 985431231;

int N,M,T;
int board[101][101];
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0};

int bfs(int final_y, int final_x){
    bool check[101][101]={false};
    queue<pair<int,int>> q;
    q.push({0,0});
    int time=0;
    check[0][0] = true;
    
    while(!q.empty()){
        time++;
        int temp = q.size();
        
        for(int j=0; j<temp; j++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
//            cout << j <<" y : " << y << " x : " << x << endl;
            for(int i=0; i<4; i++){
                if( y+dir_y[i] >= 0 && y+dir_y[i] < N && x+dir_x[i] >= 0 && x+dir_x[i] < M && !check[y+dir_y[i]][x+dir_x[i]]){
                    if(y+dir_y[i] == final_y && x+dir_x[i] == final_x) return time;
                    if(board[y+dir_y[i]][x+dir_x[i]] != 1){
//                        cout << y+dir_y[i] << " " <<  x+dir_x[i] << endl;
                        q.push({ y+dir_y[i], x+dir_x[i] });
                        check[y+dir_y[i]][x+dir_x[i]] = true;
                    }
                }
            }
        }
    }
    return INF;
}

int main(){
    cin >> N >> M >> T;
    int sword_y=0, sword_x=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2){
                sword_x = j;
                sword_y = i;
            }
        }
    }
    
    int ans = min(bfs(sword_y, sword_x) + (N-sword_y-1) + (M-sword_x-1), bfs(N-1,M-1));
//    cout << bfs(sword_y, sword_x) + (N-sword_y-1) + (M-sword_x-1) << " " <<  bfs(N-1,M-1) << endl;
    
    if(ans > T) cout << "Fail" << endl;
    else cout << ans << endl;
    
    return 0;
}
