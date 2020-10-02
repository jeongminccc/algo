//
//  10826_피보나치수 4.cpp
//  algo
//
//  Created by jm on 2020/09/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

string fibo[10001];

string sum(string a, string b){
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    while(a.length() > b.length()) b += "0";
    while(a.length() < b.length()) a += "0";
    
    int carry = 0, num=0;
    string result="";
    for(int i=0; i<a.length(); ++i){
        num = (a[i] - '0' + b[i] - '0' + carry) % 10;
        result += to_string(num);
        carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
    }

    if(carry != 0) result += to_string(carry);
    reverse(result.begin(), result.end());
    
    return result;
}

int main(){
    fibo[0] = "0"; fibo[1] = "1";

    int n;
    cin >> n;
    for(int i=2; i<=n; ++i){
        fibo[i] = sum(fibo[i-1], fibo[i-2]);
    }
    cout << fibo[n];
}
