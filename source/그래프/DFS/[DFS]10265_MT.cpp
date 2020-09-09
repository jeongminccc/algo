//
//  [DFS]10265_MT.cpp
//  algo
//
//  Created by jm on 2020/09/09.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, K;
int people[1001];
bool check[1001];
int cycle_num[1001]; // 몇번째 사이클에 속해있는지 번호
int cycle = 1;
int temp_ans = 0;
int dp[1001][1001];
vector<vector<int>> cntPerCycle(1001); // i번째 사이클에 들어있는 정답 값들

int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

bool isPossible(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int Dfs(int i, int cnt){ // cycle의 번호를 리턴해줌
    check[i] = true;
    if(cycle_num[people[i]] != 0) cycle_num[i] = cycle_num[people[i]];
    
    if(!check[people[i]])
        cycle_num[i] = Dfs(people[i], cnt+1);
    else{
        temp_ans = cnt;
        if(cycle_num[i] != 0){
            return cycle_num[i];
        }
        else {cycle_num[i] = cycle; cycle++;}
    }
    
    return cycle_num[i];
}

int knapsack(int sum, int cnt){
    if(cnt >= cycle) return sum;
    
    int& ret = dp[sum][cnt];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = max(ret, knapsack(sum, cnt+1));
    for(int i=0; i<cntPerCycle[cnt].size(); ++i){
        if(sum + cntPerCycle[cnt][i] <= K) ret = max(ret, knapsack(sum + cntPerCycle[cnt][i], cnt+1));
    }
    
    return ret;
}

int main(){
    cin >> N >> K;
    
    for(int i=1; i<=N; ++i)
            cin >> people[i];
    
    for(int i=1; i<=N; ++i){
        memset(check, false, sizeof(check));
        int temp_cycle = Dfs(i, 1);
        cntPerCycle[temp_cycle].push_back(temp_ans);
        for(int i=1; i<=N; ++i) cout << cycle_num[i] << " ";
        cout << endl;
    }
    
    for(int i=1; i<cycle; ++i) {
        for(int j=0; j<cntPerCycle[i].size(); ++j) cout << cntPerCycle[i][j] << " ";
        sort(cntPerCycle[i].begin(), cntPerCycle[i].end());
        cntPerCycle[i].erase(unique(cntPerCycle[i].begin(), cntPerCycle[i].end()), cntPerCycle[i].end());
        for(int j=0; j<cntPerCycle[i].size(); ++j) cout << cntPerCycle[i][j] << " ";
        cout << endl;
    }
    
    memset(dp, -1, sizeof(dp));
    // knapsack으로 풀것
    cout << knapsack(0,1);
    
    return 0;
}
