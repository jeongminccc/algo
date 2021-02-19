//
//  1904_01타일.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
const int MOD = 15746;

int N, cache[MAX];

int tile(int left){
    if(left == 0) return 1;
    
    int& ret = cache[left];
    if(ret != -1) return ret;
    ret = 0;
    
    if(left >= 2) ret = (ret + tile(left-2)) % MOD;
    ret = (ret + tile(left-1)) % MOD;
    
    return ret;
}
int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int ans = tile(N);
    
    cout << ans << endl;
    return 0;
}
