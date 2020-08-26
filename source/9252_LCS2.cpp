//
//  9252_LCS2.cpp
//  algo
//
//  Created by jm on 2020/08/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000 + 1;

int dp[MAX][MAX] = {0};

int main(){
    string lcs1, lcs2;
    cin >> lcs1 >> lcs2;
    
    for(int i=1; i<=lcs2.size(); i++){
        for(int j=1; j<=lcs1.size(); j++){
            if(lcs1[j-1] == lcs2[i-1])  dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int y = (int)lcs1.size(), x = (int)lcs2.size();
    int ans = dp[x][y];
    cout << ans << endl;
    
    vector<char> v;
    while(ans){
        if(dp[x][y] == ans){
            if(dp[x][y-1] == ans && y-1 != 0) y--;
            else{
                if(dp[x-1][y] == ans && x-1 != 0) x--;
                else{
                    v.push_back(lcs2[x-1]);
                    x--; y--; ans--;
                }
            }
        }
    }
    for(int i=(int)v.size()-1; i>=0; --i) cout << v[i];
    cout << endl;
    return 0;
}
