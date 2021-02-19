//
//  2343_기타레슨.cpp
//  algo
//
//  Created by jm on 2020/08/31.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;

int N, M, lesson[MAX], hi=0,lo=0;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> lesson[i];
        hi += lesson[i];
        lo = max(lo, lesson[i]);
    }
        
    
    int ans =0;
    while(lo <= hi){ // 양쪽 다 가능
        int mid = (lo+hi)/2;
       
        int bluelaySum = 1, lessonSum=0;
        for(int i=0; i<N; i++){
            lessonSum += lesson[i];
            if(lessonSum > mid){
                lessonSum = lesson[i];
                bluelaySum++;
            }
        }
        if(bluelaySum > M){
            lo = mid + 1;
        }else{
            ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}

