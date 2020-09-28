//
//  IGRUS_D.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int dp[11];

int main(){
    int seedMoney, year;
    cin >> seedMoney >> year;
    
    
    dp[0] = seedMoney;
    for(int i=1; i<=year; ++i){
        dp[i] = dp[i-1] * 1.05;
        if(i >= 3){
            int threeYear = dp[i-3] * 1.20;
            dp[i] = max(threeYear, dp[i]);
        }
        if(i >= 5) {
            int fiveYear = dp[i-5] * 1.35;
            dp[i] = max(fiveYear, dp[i]);
        }
    }
    cout << dp[year];
}
