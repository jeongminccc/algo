//
//  14003_가장 긴 증가하는 부분 수열 5.cpp
//  algo
//
//  Created by jm on 2020/08/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
int n, dp[1000001], c[1000001], c_index[1000001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> dp[i];
    
    int pos_c=1;
    c[0] = dp[0];
    c_index[0] = 1;
    
    for(int i=1; i<n; i++){
        if(c[pos_c - 1] < dp[i]) {
            c[pos_c] = dp[i];
            pos_c++;
            c_index[i] = pos_c;
        }else{
            auto it = lower_bound(c, c + pos_c, dp[i]);
            *it = dp[i];
            c_index[i] = it - c + 1;
        }
    }
    cout << pos_c << endl;
    
    vector<int> ans;
    for(int i = n-1; i>=0; --i){
        if(c_index[i] == pos_c) {
            ans.push_back(dp[i]);
            pos_c--;
        }
    }
    for(int i = ans.size() - 1; i>=0; --i) cout << ans[i] << " ";
    
    return 0;
}
