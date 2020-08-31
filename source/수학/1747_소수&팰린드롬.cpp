//
//  1747_소수&팰린드롬.cpp
//  algo
//
//  Created by jm on 2020/08/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e6 + 1;

bool checkPrime[MAX];
vector<int> prime;
int N;

void eratos(){
    for(int i=2; i<MAX; i++){
        if(!checkPrime[i]){
            checkPrime[i] = true;
            prime.push_back(i);
        }
        for(int j=i+i; j<MAX; j+=i)
            checkPrime[j] = true;
    }
}

bool check_palindrome(int num){
    string str = to_string(num);
    
    for(int i=0; i<=(str.length()-1)/2; i++){
        if(str[i] != str[str.length()-i-1]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    eratos();
    
    cin >> N;
    auto iter = lower_bound(prime.begin(), prime.end(), N);
    
    for(auto start = iter; start < prime.end(); start++){
        if(check_palindrome(*start)){
            cout << *start << endl;
            return 0;
        }
    }
    
    
    return 0;
}
