//
//  12015_가장 긴 증가하는 부분 수열 2.cpp
//  algo
//
//  Created by jm on 2020/08/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
int n, dp[1000001], c[1000001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> dp[i];
    
    c[0] = dp[0];
    int pos_c = 1;
    
    for(int i=1; i<n; i++){
        if(c[pos_c - 1] < dp[i]){
            c[pos_c] = dp[i];
            pos_c++;
        }else{
            auto key = lower_bound(c, c + pos_c, dp[i]);
            *key = dp[i];
        }
    }
    
    cout << pos_c << endl;
    return 0;
}
