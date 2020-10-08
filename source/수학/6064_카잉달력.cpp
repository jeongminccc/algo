//
//  6064_카잉달력.cpp
//  algo
//
//  Created by jm on 2020/10/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int GCD(int x, int y){
    if(y == 0) return x;
    
    return GCD(y, x % y);
}

int LCM(int x, int y){
    return x * y / GCD(x,y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N, M, x, y;
        cin >> M >> N >> x >> y;
        
        int maxYear = LCM(N,M);

        while(x <= maxYear && (x - 1) % N + 1 != y){
            x += M;
        }
        
        if(x <= maxYear) cout << x << '\n';
        else cout << "-1" << '\n';
    }
}

