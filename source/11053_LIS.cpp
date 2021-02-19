//
//  11053_LIS.cpp
//  algo
//
//  Created by jm on 2020/08/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int n, a[1000];
int cache[1001];

int lis(int start){
    int& ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    
    for(int next = start + 1; next < n; ++next){
        if(a[start] < a[next])
            ret = max(ret, lis(next)+1);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    memset(cache, -1, sizeof(cache));
    int ans = lis(-1)-1;
    cout << ans << endl;
    return 0;
}
