//
//  2225_합분해.cpp
//  algo
//
//  Created by jm on 2020/08/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9;

int N, K;
int cache[501][201]; // 공간복잡도 O(n^2)

int foo(int beforeSum, int leftCnt){ // 시간복잡도 - 부분문제의 개수 O(NK) + 실행문 O(N) = O(N^2K) 200이므로 충분히 가능.
    if(beforeSum > N) return 0;
    if(leftCnt == 0) return beforeSum == N ? 1 : 0;
    
    int& ret = cache[beforeSum][leftCnt];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int plusSum=0; plusSum <= N; ++plusSum){
        ret = (ret + foo(beforeSum + plusSum, leftCnt - 1)) % MAX;
    }
    
    return ret;
}

int main(){
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));
    int ans = foo(0, K) % MAX;
    
    cout << ans << endl;
    
    return 0;
}
