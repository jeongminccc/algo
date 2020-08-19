//
//  신촌_div2_B.cpp
//  algo
//
//  Created by jm on 2020/08/19.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>

using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, x, coefficient=0, degree;
    cin >> n >> x;
    ll ans= 0;
    
    for(int i=0; i<=n; i++){
        cin >> coefficient >> degree;
        if(i==n){
            ans = (ans + coefficient) % MOD;
            break;
        }
        ans = (x * ((ans+coefficient) % MOD)) % MOD;
    }
    
    cout << ans << endl;
    return 0;
}
