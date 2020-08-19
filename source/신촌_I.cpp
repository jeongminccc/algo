//
//  신촌_I.cpp
//  
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
typedef long long ll;

int n;
bool isprime[MAX];
vector<ll> prime, divisor;

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
    ll ret=1, pos=0;
    
    while(v>1 && pos < prime.size()){
        ll p=1;
        while(v%prime[pos]==0){
            v/=prime[pos];
            p*=prime[pos];
        }
        ret *= (p - (p/prime[pos]));
        pos++;
    }
    
    if(v!=1) ret *= (v-1);
    return ret;
}

int main(){
    cin >> n;
    primeCheck();
    
    for(ll i=1; i*i<=n; i++){ // n의 약수들 구하기
        if(n % i == 0) divisor.push_back(n/i);
    }
    reverse(divisor.begin(), divisor.end()); // 작은수 부터 세기위해서
    
    for(auto i : divisor){ // 약수들에 한해서만 서로소갯수 구한뒤 검사
        if(foo(i) * i == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    
    return 0;
}

// N의 약수들을 구하고 -> 약수들만 검사해주자.
// 그럼 약수들을 구하는 방법은?????
// root(N)까지만 검사해준뒤 약수들의 쌍을 구하면 root(N)시간에 구할 수 있음.
// 그렇게 구한 약수들에만 서로소 갯수를 센뒤 검사

// 소수의 개수를 셀때에는, n까지의 모든 소수를 세자 그래봤자 root(N)에 구할 수 있음.
