//
//  2629_양팔저울.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e4;

int N, M;
bool cache[MAX+1][31];
bool dp[MAX+1] = {false};
int weight[31];

void foo(int sum, int cnt){
    if(cnt > N) return;
    
    if(cache[sum][cnt]) return;
    cache[sum][cnt] = true;

    foo(sum, cnt+1); // 이번 추는 더하거나 뺴지않고 진행
    foo(sum + weight[cnt], cnt+1); // 이번 추를 더하고 진행
    foo(abs(sum - weight[cnt]), cnt+1); // 이번 추를 빼고 진행
    
    return;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> weight[i];
    
    memset(cache, false, sizeof(cache));
    foo(0, 0);
    
    cin >> M; int t;
    while(M--){
        cin >> t;
        bool flag = false;
        for(int i=0; i<31; i++)
            if(cache[t][i]) {
                cout << "Y ";
                flag = true;
                break;
            }
        if(!flag) cout << "N ";
    }cout << endl;
    
    return 0;
}
