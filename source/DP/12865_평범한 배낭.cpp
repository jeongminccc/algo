//
//  12865_평범한 배낭.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int,int> arr[101];
int dp[100001][101];

int foo(int sum, int cnt){
    if(cnt >= N || sum >= K) return 0;
    
    int& ret = dp[sum][cnt];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = max(ret, foo(sum, cnt+1));
    if(sum + arr[cnt].first <= K) ret = max(ret, foo(sum + arr[cnt].first, cnt+1) + arr[cnt].second);
    
    return ret;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+N);
    memset(dp, -1, sizeof(dp));
    int ans = foo(0,0);
    
    cout << ans << endl;
    return 0;
}
