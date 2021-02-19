//
//  1012_유기농배추.cpp
//  algo
//
//  Created by jm on 2020/08/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
#define PAIR pair<int,int>

int board_cabbage[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int T, M, N, cabbage, c_x, c_y;
    cin >> T;
    while(T--){
        cin >> M >> N >> cabbage;
        memset(board_cabbage, 0, sizeof(board_cabbage));
        while(cabbage--){
            cin >> c_x >> c_y;
            board_cabbage[c_x][c_y] = 1;
        }
        
        int num=0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board_cabbage[i][j] == 1) {
                    num++; // 벌레를 한 마리 둠
                    board_cabbage[i][j] = 2;
                    queue<PAIR> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        PAIR t = q.front();
                        q.pop();
                        
                        for (int dir = 0; dir < 4; dir++) {
                            if (t.first + dx[dir] < 0 || t.first + dx[dir] >= M || t.second + dy[dir] < 0 || t.second + dy[dir] >= N)
                                continue;
                            if (board_cabbage[t.first + dx[dir]][t.second + dy[dir]] == 1) {
                                q.push(make_pair(t.first + dx[dir], t.second + dy[dir]));
                                board_cabbage[t.first + dx[dir]][t.second + dy[dir]] = 2;
                            }
                        }
                    }
                }
            }
        }cout << num << endl;
    }
}
