//
//  2230_수 고르기.cpp
//  algo
//
//  Created by jm on 2020/10/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, arr[100001];
    cin >> n >> m;
    
    for(int i=0; i<n; ++i) cin >> arr[i];
    
    sort(arr, arr+n);
    
    int l=0,r=1,sum=arr[r] - arr[l], ret=2e9+1;
    while(r < n){
        if(sum < m){
            r++;
        }else{
            ret = min(ret, sum);
            l++;
        }
        sum = arr[r] - arr[l];
    }
    cout << ret;
}
