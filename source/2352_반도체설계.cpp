//
//  2352_반도체설계.cpp
//  algo
//
//  Created by jm on 2020/08/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int arr[40001], dp[40001];

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int pos=1;
    dp[0] = arr[0];
    for(int i=1; i<N; i++){
        if(arr[i] > dp[pos-1]){
            dp[pos] = arr[i];
            pos++;
        }else{
            auto it = lower_bound(dp, dp+pos, arr[i]);
            *it = arr[i];
        }
    }
    cout << pos << endl;
    return 0;
}
