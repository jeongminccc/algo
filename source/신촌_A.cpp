//
//  신촌_A.cpp
//  
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<ll,ll> arr[100001];
int n, pos_a=0, pos_b=0;
ll sum[100001][2] = {0};

int foo(int i, ll pos, bool flag){
    
    if(i == n) return 1;
    
    if(!flag && (sum[i][0] > arr[i].first)){ // 한번 부족한 일이 생겼을때
        return foo(i, sum[i][1], true) + foo(i+1, arr[i].second, true);
    }
    if(flag){ // 2번째 부족해질때
        if((sum[i][0] - pos) > arr[i].first){
            return 0;
        }
    }
    return foo(i+1, pos, flag);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if(i == 0) continue;
        sum[i][0] = sum[i-1][0] + arr[i-1].second; // 이때까지 모은 상금의 합
        sum[i][1] = max(sum[i-1][1], arr[i-1].second); // 이때까지 상금 중 최대
    }
    
    if(foo(0, 0, false) == 0) cout << "Zzz" << endl;
    else cout << "Kkeo-eok" << endl;
    
    return 0;
}
