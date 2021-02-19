//
//  1958_LCS3.cpp
//  algo
//
//  Created by jm on 2020/08/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 100 + 10;

int dp[MAX][MAX][MAX];

int main(){
    string a,b,c;
    cin >> a >> b >> c;

    for(int i=0; i<a.length(); i++){
        for(int j=0; j<b.length(); j++){
            for(int k=0; k<c.length(); k++){
                if(a[i] == b[j] && b[j] == c[k]) dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                else dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k], max(dp[i+1][j][k+1], dp[i][j+1][k+1]));
            }
        }
    }
    cout << dp[a.length()][b.length()][c.length()] << endl;
    
    return 0;
}
