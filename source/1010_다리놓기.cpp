//
//  1010_다리놓기.cpp
//  algo
//
//  Created by jm on 2020/09/27.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, R, dp[30][30];

int combination(int depth, int pos){
    
    int& ret = dp[depth][pos];
    if(ret != -1) return ret;
    ret = 0;
    
    if(depth == R) return ret = 1;
    
    for(int i=pos; i<N; ++i)
        ret += combination(depth + 1, i + 1);
    
    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> R >> N;
        cout << combination(0, 0) << endl;
    }
}
