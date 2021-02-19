//
//  6591_이항쇼다운.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//const int MOD = 10007;

int N, K;
ll comb(ll a, ll b){
    b = min(b, a-b);
    ll ret = 1;
    
    for(int i=1; i<=b; i++){
        ret *= a;
        ret /= i;
        a--;
    }
    
    return ret;
}

int main(){
    while(1){
        cin >> N >> K;
        if(N == 0 && K == 0) break;
        ll ans = comb(N, K);
        
        cout << ans << endl;
    }
    return 0;
}
