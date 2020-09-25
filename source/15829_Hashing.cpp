//
//  15829_Hashing.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1234567891;
 
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 0;
    long long val = 1;
    for(int i=0; i<s.size(); ++i){
        ans = (ans + (s[i] - 'a' + 1) * val) % MOD;
        val = (val * 31) % MOD;
    }
    
    cout << ans;
}
