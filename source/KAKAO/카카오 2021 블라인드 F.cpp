//
//  카카오 2021 블라인드 F.cpp
//  algo
//
//  Created by jm on 2020/09/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int INF = 1e9;

struct STRUCT{
    vvi v;
    pii p;
    int ret=0;
};

int answer = INF;
int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
vvi ans;

int CalCnt(vvi& v, int pos_r, int pos_c, int goal_r, int goal_c){ // 목표거리 까지의 최소 거리 계산
    int ret = 0, ret2=0;
    int cardCnt = 0; // 중간에 카드가 몇개나 있는지
    bool flag_r = false, flag_c = false;
    int pos_r2 = pos_r, pos_c2 = pos_c;
    
    int go=0;
    while(pos_r != goal_r){
        flag_r = true; // 이 방향으로 움직였음을 체크
        go++;
        if(pos_r < goal_r){
            pos_r++;
            if(v[pos_r][pos_c] != 0 && pos_r != goal_r) cardCnt++;
        }else{
            pos_r--;
            if(v[pos_r][pos_c] != 0 && pos_r != goal_r) cardCnt++;
        }
    }
    if(flag_r){
        if(go == 2 && cardCnt == 0 && pos_r != 0 && pos_r != 3 && v[pos_r][pos_c] == 0) ret += 2;
        else ret += cardCnt + 1;
    }
    
    cardCnt =0; go = 0;
    while(pos_c != goal_c){
        flag_c = true; // 이 방향으로 움직였음을 체크
        go++;
        if(pos_c < goal_c){
            pos_c++;
            if(v[pos_r][pos_c] != 0 && pos_c != goal_c) cardCnt++;
        }else{
            pos_c--;
            if(v[pos_r][pos_c] != 0 && pos_c != goal_c) cardCnt++;
        }
    }
    if(flag_c){
        if(go == 2 && cardCnt == 0 && pos_c != 0 && pos_c != 3 && v[pos_r][pos_c] == 0) ret += 2;
        else ret += cardCnt + 1;
    }
    
    cardCnt =0;go = 0;
    flag_r = false; flag_c = false;
    while(pos_c2 != goal_c){
        flag_c = true; // 이 방향으로 움직였음을 체크
        go++;
        if(pos_c2 < goal_c){
            pos_c2++;
            if(v[pos_r2][pos_c2] != 0 && pos_c2 != goal_c) cardCnt++;
        }else{
            pos_c2--;
            if(v[pos_r2][pos_c2] != 0 && pos_c2 != goal_c) cardCnt++;
        }
    }
    if(flag_c){
        if(go == 2 && cardCnt == 0 && pos_c2 != 0 && pos_c2 != 3 && v[pos_r2][pos_c2] == 0) ret2 += 2;
        else ret2 += cardCnt + 1;
    }
    
    cardCnt = 0;go = 0;
    while(pos_r2 != goal_r){
        flag_r = true; // 이 방향으로 움직였음을 체크
        go++;
        if(pos_r2 < goal_r){
            pos_r2++;
            if(v[pos_r2][pos_c2] != 0 && pos_r2 != goal_r) cardCnt++;
        }else{
            pos_r2--;
            if(v[pos_r2][pos_c2] != 0 && pos_r2 != goal_r) cardCnt++;
        }
    }
    if(flag_r){
        if(go == 2 && cardCnt == 0 && pos_r2 != 0 && pos_r2 != 3 && v[pos_r2][pos_c2] == 0) ret2 += 2;
        else ret2 += cardCnt + 1;
    }
    
    return min(ret,ret2);
}



void Bfs(vvi v, int r, int c){
    int cardNum = 0, next_r=0, next_c=0, ret=0;
    queue<STRUCT> q;
    STRUCT s;
    s.v = v;
    s.p = {r,c};
    s.ret = 0;
    q.push(s);
    
    while(!q.empty()){
        vvi next_v = q.front().v;
        r = q.front().p.first;
        c = q.front().p.second;
        ret = q.front().ret;
        q.pop();
        
        if(next_v == ans){
            answer = min(answer, ret);
            continue;
        }
        
        if(next_v[r][c] != 0){ // 카드 뒤집기
            cardNum = next_v[r][c];
            next_v[r][c] = 0;
            for(int i=0; i<4; ++i)
                for(int j=0; j<4; ++j)
                    if(next_v[i][j] == cardNum){
                        next_r = i;
                        next_c = j;
                    }
            
            ret += CalCnt(next_v, r, c, next_r, next_c) + 2; // 엔터 두번 + 이동 중 방향키
            next_v[next_r][next_c] = 0;
            STRUCT a; a.v = next_v; a.p = {next_r, next_c}; a.ret = ret;

//            cout << r << " " << c << " " << next_r << " " << next_c << " " << CalCnt(next_v, r, c, next_r, next_c) << endl;
            q.push(a);
        }
        
        else{ // 가장 가까운 카드까지 이동
            for(int i=0; i<4; ++i){
                for(int j=0; j<4; ++j){
                    if(next_v[i][j] != 0){ // 이 카드까지 이동
//                        cout << r << " " << c << " " << i << " " << j << " " << CalCnt(next_v, r, c, i, j) << endl;
                        STRUCT a; a.v = next_v; a.p = {i, j}; a.ret = ret + CalCnt(next_v, r, c, i, j);
                        q.push(a);
                    }
                }
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    ans = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    
    Bfs(board, r, c);
    return answer;
}

int main(){
    vvi a = {{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}};
    solution(a, 0, 1);
    
}
