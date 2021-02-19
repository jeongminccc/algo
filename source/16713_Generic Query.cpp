//
//  16713_Generic Query.cpp
//  algo
//
//  Created by jm on 2020/09/17.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    // 입력받으면서 prefix sum을 채움(행, 열 1칸씩 더 필요함에 유의)
    int N, M, pSum[1000001] = {0};
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        pSum[i+1] = pSum[i] ^ A;
    }
    
    int ans=0;
    for(int i=0; i<M; ++i){
        int from, to;
        cin >> from >> to;
        ans ^= pSum[to] ^ pSum[from-1];
    }
    cout << ans << "\n";
}
