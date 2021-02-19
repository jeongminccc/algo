//
//  1300_K번째 수.cpp
//  algo
//
//  Created by jm on 2020/08/31.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e10 + 1;

ll N, k;

int main(){
    cin >> N >> k;
    
    ll lo = 1, hi = MAX;
    while(lo + 1 < hi){ // lo를 답으로 할것, 반대쪽인 hi는 답이 될 수 없도록 초기화
        ll mid = (lo+hi)/2;
        
        ll sum = 0;
        for(int i=1; i<=N; i++)
            if(i <= mid-1) sum += min(N, ((mid-1)/i));
            
        cout << mid << endl;
        if(sum < k) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
    
    return 0;
}


