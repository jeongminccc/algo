//
//  11051_이항계수2.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;


int N, K, cache[1001][1001];

int foo(int n, int k){
    if(k == 0 || n == k) return 1;
    
    int& ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    
    return ret = (foo(n-1, k-1) + foo(n-1, k)) % MOD;
}

int main(){
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    
    int ans = foo(N,K) % MOD;
    
    cout << ans << endl;
    return 0;
}
