//
//  2512_예산.cpp
//  algo
//
//  Created by jm on 2020/08/31.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 1;

int N, province[MAX], budget=0, hi=0;

int main(){
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> province[i];
        hi = max(hi, province[i]);
    }
    cin >> budget;
    
    int lo = 0;
    hi++;
    while(lo + 1 < hi){
        int mid = (lo + hi)/2;
        
        int sumOfprovince = 0;
        for(int i=0; i<N; i++) sumOfprovince += min(province[i], mid);
        
        if(sumOfprovince <= budget) lo = mid;
        else hi = mid;
    }
    
    cout << lo << endl;
    return 0;
}

