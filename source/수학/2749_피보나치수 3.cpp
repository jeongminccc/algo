//
//  2749_피보나치수 3.cpp
//  algo
//
//  Created by jm on 2020/10/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1500000;

int main(){
    long long num;
    int fibo[1500001];
    cin >> num;

    num %= MOD;

    fibo[0] = 0; fibo[1] = 1;
    for(int i=2; i<=num; ++i)
        fibo[i] = (fibo[i-2] + fibo[i-1]) % 1000000;

    cout << fibo[num];
}
