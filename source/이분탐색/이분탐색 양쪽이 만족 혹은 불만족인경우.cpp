//
//  이분탐색 양쪽이 만족 혹은 불만족인경우.cpp
//  algo
//
//  Created by jm on 2020/08/31.
//  Copyright © 2020 jm. All rights reserved.
//

// 먼저 양쪽(lo, hi) 모두 답이 될 수있는 경우
while(lo <= hi){
    int mid = (lo + hi)/2;

    int sumOfprovince = 0;
    for(int i=0; i<N; i++) sumOfprovince += min(province[i], mid);
    
    if(sumOfprovince <= budget){
        int ans = mid; // 이 조건이 있어야 답을 넘어가지 않음.
        lo = mid + 1;
    }
    else hi = mid - 1;
}

// 한쪽이 답이 될 수 없는 경우
while(lo + 1 < hi){
    int mid = (lo + hi)/2;
    
    int sumOfprovince = 0;
    for(int i=0; i<N; i++) sumOfprovince += min(province[i], mid);
    
    if(sumOfprovince <= budget) lo = mid; // [15,16]인 경우 16은 불만족이므로 15를 답으로 저장후 끝냄.
    else hi = mid;
}
