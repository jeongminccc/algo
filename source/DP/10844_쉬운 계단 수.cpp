//
//  10844_쉬운 계단 수.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9;


int N, cache[10][101];
int foo(int start, int left){
    if(left == 0) return 1;
    
    int& ret = cache[start][left];
    if(ret != -1) return ret;
    ret = 0;
    
    if(start != 9) ret = (ret + foo(start+1, left-1)) % MAX;
    if(start != 0) ret = (ret + foo(start-1, left-1)) % MAX;
    
    return ret;
}

int main(){
    cin >> N;
    
    int ans = 0;
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<10; i++) ans = (ans + foo(i, N-1)) % MAX;
    
    cout << ans;
    return 0;
}
