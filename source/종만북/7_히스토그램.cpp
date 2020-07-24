//
//  7_히스토그램.cpp
//  algo
//
//  Created by jm on 2020/07/24.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> h;

ll solve(int left, int right){
    int mid = (left+right) / 2;
    ll ret = 0;
    
    if(left == right) return h[left];
        
    ret = max(solve(left, mid), solve(mid+1, right));
    
    ll lo = mid, hi =  mid+1;
    ll height = min(h[lo],h[hi]);
    ll tmp_ans = height * 2;
    ret = max(ret, tmp_ans);
    
    while(lo >= left && hi <= right){
        if(lo > left && ( h[lo-1] > h[hi+1] || hi == right) ){
            lo--;
            height = min(height, h[lo]);
        }else{
            hi++;
            height = min(height, h[hi]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, temp; cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        h.push_back(temp);
    }
    
    ll ans=0;
    
    ans = solve(0,n-1);
    
    cout << ans;
    
    return 0;
}
