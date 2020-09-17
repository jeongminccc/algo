//
//  10986_나머지 합.cpp
//  algo
//
//  Created by jm on 2020/09/16.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 10;
const int M = 1e3 + 10;

long long psum[MAX];
int psumMod[MAX];
long long ans[M]={0};

int main()
{
    int N, M;
    long long ret=0;
    cin >> N >> M;
    
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        psum[i+1] = psum[i] + a; // psum[1]이 첫번째 원소 포함한 누적합
        psumMod[i] = psum[i+1] % M;
    }
    
    for(int i=0; i<N; ++i){
        if(psumMod[i] == 0) ret++;
        ans[psumMod[i]]++;
    }
    
    for(int i=0; i<=M; ++i){
        if(ans[i] > 1){ // psum % M == i인 구간합 원소가 2개 이상 있다는 뜻. 2개면 총 1개의 조합, 3개면 3개의조합 4개면 6개
            ret += (ans[i] * (ans[i] - 1)) / 2;
        }
    }
    cout << ret;
    return 0;
}
