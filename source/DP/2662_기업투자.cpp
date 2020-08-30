//
//  2662_기업투자.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, M ;
int inv[301][21]; // 각 투자 금액 별 이익과 기업의 번호
int dp[301][21]; // 답을 구하는 dp배열, 첫번째칸에는 투자 금액별 최대 이익이, 두번째 ~ M+1 칸에는 기업별 투자한 금액이 저장
int invested[301][21]; // 얼마나 투자를 했는지 저장

int foo(int sumOfInvest, int company){
    if(company > M) return 0;
    
    int& ret = dp[sumOfInvest][company];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int invest=0; invest <= sumOfInvest; invest++){
        // 각 투자금액
        int temp = inv[invest][company] + foo(sumOfInvest - invest, company+1);
        if(ret < temp){ // 이번 company에 invest만큼 투자했을때의 이익이 가장 높다면
            ret = temp;
            invested[sumOfInvest][company] = invest;
        }
    }
    return ret;
}
int main(){
    cin >> N >> M;
    
    int invest;
    for(int i=1; i<=N; i++){
        cin >> invest;
        for(int j=1; j<=M; j++) cin >> inv[invest][j];
    }
    memset(dp, -1, sizeof(dp));
    
    cout << foo(N, 1) << endl; // N만큼 투자했을때 최대 이익 출력
    
    int totalInvest = N;

    for (int i = 1; i <= M; i++){
         cout << invested[totalInvest][i] << " ";
         totalInvest -= invested[totalInvest][i];
    }
    cout << endl;

    return 0;
}

