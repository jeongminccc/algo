//
//  14002_가장 긴 증가하는 부분 수열 4.cpp
//  algo
//
//  Created by jm on 2020/08/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
int n, dp[1001], c[1001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> dp[i];
    
    int lis = 0, ans=0, ans_i=0;
    for(int i=0; i<n; i++){
        lis = 0;
        vector<int> temp;
        for(int j=0; j<i; j++){
            if(dp[i] > dp[j]) {
                if(lis < c[j]) {
                    lis = c[j];
                    temp = lis_list[j];
                }
            }
        }
        lis++;
        c[i] = lis;
        if(ans < lis){
            ans = lis;
            ans_i = i;
        }
        temp.push_back(dp[i]);
        lis_list.push_back(temp);
    }
    
    cout << ans << endl;
    for(int i=0; i<lis_list[ans_i].size(); i++) cout << lis_list[ans_i][i] << " ";
    
    return 0;
}
