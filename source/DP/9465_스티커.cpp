//
//  9465_스티커.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5;

int N, dp[2][MAX+10];

int main(){
    int test_case;
    cin >> test_case;
    
    while(test_case--){
        cin >> N;
        for(int i=1; i<=N; i++) cin >> dp[0][i];
        for(int i=1; i<=N; i++) cin >> dp[1][i];
        
        int ans = 0;
        for(int i=2; i<=N; i++){
            for(int j=0; j<2; j++){
                if(j==0) dp[j][i] += max(dp[1][i-1], dp[1][i-2]);
                else dp[j][i] += max(dp[0][i-1], dp[0][i-2]);
                ans = max(ans, dp[j][i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
