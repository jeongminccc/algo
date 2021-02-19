//
//  2042_구간 합 구하기(펜윅트리).cpp
//  algo
//
//  Created by jm on 2020/09/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N,M,K;
ll original[1000001];
ll fenwick[1000001];

ll fenwick_sum(int index){
    ll ans = 0;
    while(index){
        ans += fenwick[index];
        index -= (index & -index);
    }
    return ans;
}

void fenwick_update(int index, ll dif){
    while(index <= N){
        fenwick[index] += dif;
        index += (index & -index);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) {
        cin >> original[i];
        fenwick_update(i, original[i]);
    }
    
    int test;
    
    while(M>0 || K>0){
        cin >> test;
        if(test == 1){
            int index;
            ll new_num;
            cin >> index >> new_num;
            ll dif = new_num - original[index];
            original[index] = new_num;
            fenwick_update(index, dif);
            M--;
        }else{
            int from, to;
            cin >> from >> to;
            cout << fenwick_sum(to) - fenwick_sum(from - 1) << "\n";
            K--;
        }
    }
    return 0;
}


