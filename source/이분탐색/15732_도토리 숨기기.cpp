//
//  15732_도토리 숨기기.cpp
//  algo
//
//  Created by jm on 2020/08/31.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;

int N, K, acorn, A[10001], B[10001], C[10001];

int main(){
    cin >> N >> K >> acorn;
    for(int i=0; i<K; i++) cin >> A[i] >> B[i] >> C[i];
    
    int lo = 0, hi = MAX;
    while(lo + 1 < hi){ // 한쪽만 가능
        int mid = (lo+hi)/2; // mid는 몇번째 상자까지 도토리를 채울 수 있는지
       
        long long sum = 0;
        for(int i=0; i<K; i++){
            if(A[i] <= mid)
                sum += (min(B[i], mid) - A[i]) / C[i] + 1;
        }
        if(sum >= acorn){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << hi << endl;
    
    return 0;
}

