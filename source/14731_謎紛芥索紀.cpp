//
//  14731_謎紛芥索紀.cpp
//  algo
//
//  Created by jm on 2020/08/15.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

const ll MOD = 1e9+7;
ll n, coefficient, degree;
ll ans=0;

int main(){
    cin >> n;
    while(n--){
        cin >> coefficient >> degree;
        coefficient = (coefficient * degree) % MOD;
        
        ll pos = 2, temp = 1, times = degree -1;
        while(times){
            if(times & 1) temp = (temp * pos) % MOD;
            pos = pos * pos % MOD;
            times /= 2;
        }
        
        ans = (ans + (coefficient * temp) % MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}
