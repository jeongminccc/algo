//
//  2960_에라토스테네스의체.cpp
//  algo
//
//  Created by jm on 2020/07/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
bool checkPrime[40001];
vector<int> prime;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, cnt=1;
    cin >> n >> k;
    
    for(int i=2; i<=n; i++){
        if(!checkPrime[i]){
            checkPrime[i] = true; if(cnt == k) cout << i << endl;
            cnt++;
            prime.push_back(i);
        }
        for(int j=i*i; j<=n; j+=i){
            if(!checkPrime[j]){
                checkPrime[j] = true; if(cnt == k) cout << j << endl;
                cnt++;
            }
        }
    }
}
