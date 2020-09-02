//
//  1201_NMK.cpp
//  algo
//
//  Created by jm on 2020/09/02.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main(){
    cin >> N >> M >> K;
    vector<int> ans(N);
    if(N >= M + K - 1 && N <= M*K){
        int pos = N, left_K = K;
        while(pos){
            if(pos - M >= left_K - 1){
                for(int i=pos-M+1; i<=pos; ++i) cout << i << " ";
                pos -= M;
                left_K--;
            }else{
                int dif = pos - (left_K - 1);
                for(int i=pos-dif+1; i<=pos; ++i) cout << i << " ";
                pos -= dif;
                left_K--;
            }
        }
    }else{
        cout << "-1";
    }
    return 0;
}
