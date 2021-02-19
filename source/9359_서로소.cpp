//
//  9359_서로소.cpp
//  
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
#define MMAX 10000001
typedef long long ll;

int A,B,N;
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

ll foo(vector<ll>::iterator start, vector<ll>::iterator end, ll v){
    ll ret=1;
    for(auto now = start; now < end; now++){
        ll p=1;
        while(v%(*now)==0){
            v/=(*now);
            p*=(*now);
        }
        if(p!=0){
            ret*=(p-(p/(*now)));
        }
    }
    if(v!=1) ret*=(v-1);
    return ret;
}

int main(){
    int T;
    cin >> T;
    primeCheck();
    for(int i=0; i<T; i++){
        cin >> A >> B >> N;
        auto from = lower_bound(prime.begin(), prime.end(), A);
        auto to = lower_bound(prime.begin(), prime.end(), B) - 1;
        cout << *from << " " << *to << endl;
        ll ans = foo(from, to, N);
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
ll A,B,N;
int notPrime[100003];
vector<int> primes;
map<ll, int> mp;
vector<ll> divisors;
 
int main(){
    int T;
    cin >> T;
 
    for(int i = 2; i <= 100000; i++){
        if(notPrime[i]) continue;
        for(int j = 2*i; j <= 100000; j+=i){
            notPrime[j] = 1;
        }
    }
 
    for(int i = 2; i <= 100000; i++){
        if(!notPrime[i]) primes.push_back(i);
    }
    for(int t = 1; t <= T; t++){
        cin >> A >> B >> N;
        divisors.clear();
        mp.clear();
 
        while(N > 1){
            bool divided = false;
            for(auto p : primes){
                if(N % p == 0) {
                    N /= p;
                    mp[p] = 1;
                    divided = true;
                    break;
                }
            }
            if(!divided) break;
        }
 
        if(N != 1) mp[N] = 1;
 
        for(auto it = mp.begin(); it != mp.end(); it++){
            divisors.push_back((*it).first);
        }
 
        int size = divisors.size();
        ll ans = 0;
        for(int i = 0 ; i < 1<<size ; i++){
            if(!i) continue;
            int cnt = 0;
            ll div = 1;
            for(int j = 0 ; j < size; j++){
                if(i&(1<<j)) div *= divisors[j], cnt++;
            }
            ll lo = (A+div-1)/div*div;
            ll hi = B/div*div;
            if(lo>hi) continue;
            ll gasu = (hi-lo)/div + 1;
            ans += cnt%2 ? gasu : -gasu;
        }
        cout << "Case #" << t << ": " <<  B - A + 1 - ans << endl;
    }
    return 0;
}


출처: https://sgc109.tistory.com/89 [블로그 옮겼습니다]
