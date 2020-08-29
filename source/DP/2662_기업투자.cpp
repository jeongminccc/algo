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
pair<int, int> inv[301]; // 각 투자 금액 별 최대 이익과, 그 이익을 받을수 있는 기업의 index값이 들어감
int dp[301][22]; // 답을 구하는 dp배열, 첫번째칸에는 투자 금액별 최대 이익이, 두번째 ~ M+1 칸에는 기업별 투자한 금액이 저장

int main(){
    cin >> N >> M;
    
    int invest, A;
    for(int i=1; i<=N; i++){
        cin >> invest;
        int max_inv = 0, max_index=0;
        for(int j=0; j<M; j++){
            cin >> A;
            if(max_inv <= A){
                max_inv = A;
                max_index = j;
            }
        }
        inv[i].first = max_inv;
        inv[i].second = max_index;
    }
    
    for(int i=1; i<=N; i++){ // 투자 금액별 이익이 들어있는 배열을 사용
        for(int j=N; j>=i; --j){ // 맨 마지막 부터(한번씩만 사용 가능 하므로) 요소들을 넣어가며 처리
            if(dp[j][0] <= dp[j-i][0] + inv[i].first){ // inv[i]를 넣었을때 최대가 되는지
                
                dp[j][0] = dp[j-i][0] + inv[i].first; // 최대가 되면 값을 바꾸고
                for(int k=1; k<22; k++) dp[j][k] = dp[j-i][k]; // 기업별 투자금액 index도 복사후
                dp[j][inv[i].second+1] += i; // 값을 추가
            }
        }
    }
    cout << dp[N][0] << endl; // N만큼 투자했을때 최대 이익 출력
    for(int i=1; i<=M; i++) cout << dp[N][i] << " "; // 각 기업별 투자 금액 출력
    return 0;
}
