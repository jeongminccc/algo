//
//  11969_Breed Counting.cpp
//  algo
//
//  Created by jm on 2020/09/16.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N, M, psum[100001][4];
    cin >> N >> M;
    
    for(int i=1; i<=N; ++i){
        int a;
        cin >> a;
        for(int j=1; j<=3; ++j)
            psum[i][j] = psum[i-1][j];
        
        psum[i][a]++;
    }
    
    for(int i=0; i<M; ++i){
        int from, to;
        cin >> from >> to;
        
        for(int j=1; j<=3; ++j) cout << psum[to][j] - psum[from-1][j] << " ";
        cout << "\n";
    }
    
    return 0;
}

