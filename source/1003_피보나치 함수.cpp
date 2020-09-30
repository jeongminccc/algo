//
//  1003_피보나치 함수.cpp
//  algo
//
//  Created by jm on 2020/09/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
struct ST{
    int val;
    int zero;
    int one;
};

ST fibo[41];

int main(){
    fibo[0].val = 0; fibo[0].zero = 1; fibo[0].one = 0;
    fibo[1].val = 1; fibo[1].zero = 0; fibo[1].one = 1;
    
    for(int i=2; i<=40; ++i){
        fibo[i].val = fibo[i-1].val + fibo[i-2].val;
        fibo[i].zero = fibo[i-1].zero + fibo[i-2].zero;
        fibo[i].one = fibo[i-1].one + fibo[i-2].one;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fibo[n].zero << " " << fibo[n].one << '\n';
    }
}
