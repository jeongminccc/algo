//
//  1018_체스판다시칠하기.cpp
//  algo
//
//  Created by jm on 2020/07/13.
//  Copyright © 2020 jm. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
#define INF 0x1fffffff

char board[51][51];
int n,m;

int calculBoard(int x, int y){
    if(x + 7 >= n || y + 7 >= m) return INF;
    int ans_A=0, ans_B=0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int nx = x+i, ny = y+j;
            
            if( (i+j) % 2 == 0 ){
                if(board[nx][ny] == 'W') ans_A++;
                else ans_B++;
            }else{
                if(board[nx][ny] == 'B') ans_A++;
                else ans_B++;
            }
        }
    }
    
    return ans_A < ans_B ? ans_A : ans_B;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int ans=INF;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int Tmp_ans = calculBoard(i,j);
            ans = ans < Tmp_ans ? ans : Tmp_ans;
        }
    }
    
    cout << ans << endl;
    return 0;
}
