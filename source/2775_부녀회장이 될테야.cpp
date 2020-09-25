//
//  2775_부녀회장이 될테야.cpp
//  algo
//
//  Created by jm on 2020/09/23.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    int residents[15][15] = {0};
    for(int i=1; i<=14; ++i) residents[0][i] = i;
    
    for(int i=1; i<=14; ++i)
        for(int j=1; j<=14; ++j)
            residents[i][j] += residents[i-1][j] + residents[i][j-1];
    
    while(t--){
        int k, n;
        cin >> k >> n;
        cout << residents[k][n] << endl;
    }
    
}

// 3층 (0층 1) (0층 1+1+1+2) (0층 1+1+1+2+1+1+2+1+2+3)
// 2층 (0층 1) (0층 1+1+2) (0충 1+1+2+1+2+3)
// 1층 (0층 1) (0층 1+2) (0층 1+2+3)
// 0층 1 2 3
