//
//  신촌_I.cpp
//  
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
#define MMAX 10000001
typedef long long ll;

int n;
int arr[MAX] = {0};
bool isprime[MAX];
vector<ll> prime;

void primeCheck(){
    for(int i=2;i<=MAX;i++) isprime[i] = true;
    for(ll i=2;i<=MAX;i++)
        if(isprime[i]){
            prime.push_back(i);
            for(ll j=i*i;j<=MAX;j+=i)
                isprime[j] = false;
        }
}

ll foo(ll v){
    ll ret=1;
    for(auto now: prime){
        ll p=1;
        while(v%now==0){
            v/=now;
            p*=now;
        }
        if(p!=0){
            ret*=(p-(p/now));
        }
    }
    if(v!=1) ret*=(v-1);
    return ret;
}

int main(){
    cin >> n;
    for(ll i=1; i<=MMAX; i++){ // 소수들의 서로소 갯수는 항상 소수 - 1
        if(foo(i) * i == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    
    return 0;
}
