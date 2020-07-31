//
//  15897_잘못구현한에라토스.cpp
//  algo
//
//  Created by jm on 2020/07/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, pos=2;
ll ans=0;

ll foo(){
    ll var = (n-1) / pos;
    ll next = (n-1) / var;
    
    ll ret = (var+1) * (next + 1 - pos);
    pos = next + 1;
    return ret;
}

int main(){
    cin >> n;
    
    ans += n;
    while(pos < n){
        ans += foo();
    }
    if(n!=1) ans += 1;
    
    cout << ans << endl;
    return 0;
}
