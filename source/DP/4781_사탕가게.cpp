//
//  4781_사탕가게.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, candy[5001], dp[10001], int_M, money[5001];
double M, double_money;

int main(){
    while(1){
        cin >> N >> M;
        if(N == 0) break;
        int_M = (int)((M * 100) + 0.5); // 소수점 없애기
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<N; i++) {
            cin >> candy[i] >> double_money;
            money[i] = (int)((double_money * 100) + 0.5);
        }
        
        for(int i=0; i<N; i++){
            for(int j=money[i]; j<=int_M; j++){
                dp[j] = max(dp[j], dp[j-money[i]] + candy[i]);
            }
        }
        cout << dp[int_M] << endl;
    }
    return 0;
}
