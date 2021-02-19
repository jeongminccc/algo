//
//  7579_앱.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4;

int N, M, cache[MAX+1];
pair<int, int> app[101];

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> app[i].first; // 메모리의 양
    for(int i=0; i<N; i++) cin >> app[i].second; // cost
    memset(cache, 0, sizeof(cache));
    
    for(int i=0; i<N; i++) // 하나씩 넣으면서 dp를 최적화
        for(int j=10000; j>=app[i].second; --j) // j는 cost의 총 합
            cache[j] = max(cache[j], cache[j-app[i].second] + app[i].first); // cost j로 만드는 메모리의 최대값을 구해놓음
    
    for(int i=0; i<=10000; i++){ // 메모리를 M이상 사용하는 최소의 cost를 찾기위해
        if(cache[i] >= M){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
