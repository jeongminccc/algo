//
//  13398_연속합2.cpp
//  algo
//
//  Created by jm on 2020/09/15.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int N, dp[100001][2] = {0}, ans = -1e9;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int A;
        cin >> A;
        if(i == 1){
            dp[i][0] = A;
            dp[i][1] = 0;
            ans = dp[i][0];
            continue;
        }
        dp[i][0] = max(dp[i-1][0] + A, A); // 아직 하나 안버림
        dp[i][1] = max(dp[i-1][1] + A, dp[i-1][0]); // 이미 버림
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}

