//
//  2798_블랙잭.cpp
//  algo
//
//  Created by jm on 2020/09/24.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<int> bit;
    for(int i=0; i<n-3; ++i) bit.push_back(0);
    for(int i=0; i<3; ++i) bit.push_back(1);
    
    vector<int> v(n);
    for(auto& a:v) cin >> a;
    
    int ans= 0;
    do{
        int ret=0;
        for(int i=0; i<n; ++i)
            if(bit[i]) ret += v[i];
        
        if(ret <= m && ret > ans) ans = ret;
        
    }while(next_permutation(bit.begin(), bit.end()));
    cout << ans;
}
