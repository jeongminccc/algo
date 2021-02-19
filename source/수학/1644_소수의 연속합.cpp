//
//  1644_소수의 연속합.cpp
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    eratos();
    prime.push_back(MAX + 10);
    cin >> N;
    int ans = 0;
    
    for(int i=0; prime[i] <= N; i++){
        int temp_i = i, sumOfPrime=0;
        while(1){
            sumOfPrime += prime[temp_i];
            if(sumOfPrime > N) break;
            if(sumOfPrime == N){
                ans++;
                break;
            }
            temp_i++;
        }
    }
    cout << ans << endl;
    return 0;
}
