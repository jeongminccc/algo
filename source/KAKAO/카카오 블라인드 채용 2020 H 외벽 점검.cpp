//
//  카카오 블라인드 채용 2020 외벽점검.cpp
//  algo
//
//  Created by jm on 2020/09/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int Recur(priority_queue<int, vector<int>, greater<>> q, vector<int> v){
    int ret = INF;
    if(v.size() == 0) return ret;
    
    vector<int> next(v.begin()+1, v.end());
    
    bool flag = false;
    int from = q.top();
    q.pop();
    while(!q.empty()){
        int to = q.top();
        if(v[0] < to - from){ flag = true; break;}
        q.pop();
    }
    
    if(!flag) return 1;
    ret = min(ret, Recur(q, next) + 1);
    
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    
    int wSize = (int)weak.size();
    for(int i=0; i<wSize; ++i){
        vector<int> temp(dist);
        int start = weak[i];
        priority_queue<int, vector<int>, greater<>> pq, pq2;
        
        // 각 weak 지점을 기준으로 출발하며 청소하도록 해준다.
        for(int j=0; j<wSize; ++j){ // 시계 방향으로 이동
            if(weak[j] < start) pq.push(n + weak[j]);
            else pq.push(weak[j]);
        }
        
        for(int j=wSize-1; j>=0; --j){ // 반시계 방향으로 이동
            if(weak[j] < start) pq2.push(start + (start-weak[j]));
            else pq2.push(start + (n - (weak[j] - start)));
        }
        
        do{
            answer = min(answer, Recur(pq, temp));
            answer = min(answer, Recur(pq2, temp));
        }while(next_permutation(temp.begin(), temp.end()));
    }
    if(answer == INF) answer = -1;
    return answer;
}

// weak를 순서대로, 각 원소를 첫번째 원소로 잡고 가능한 경우의 수 모두 계산

int main() {
    vector<int> a = {1,5,6,10};
    vector<int> b = {1,2,3,4};
    
    cout << solution(12, a, b);
    return 0;
}

//12    [1, 5, 6, 10]    [1, 2, 3, 4]    2
//12    [1, 3, 4, 9, 10]    [3, 5, 7]    1
