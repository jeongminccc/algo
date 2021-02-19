//
//  IGRUS_F.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int n = 10;
vector<int> ans(n);
int arr[10]={0};

long long foo(int depth, int beforeNum, int beforeNum2){
    long long ret = 0;
    
    if(depth == 10){
        int co=0;
        for(int i=0; i<10; ++i) if(arr[i] == ans[i]) co++;
        
        if(co >= 5) return 1;
        else return 0;
    }
    
    for(int i=1; i<=5; ++i){
        if(beforeNum == beforeNum2 && beforeNum2 == i) continue;
        else{
            arr[depth] = i;
            ret += foo(depth+1, beforeNum2, i);
        }
    }
    
    return ret;
}

int main(){
    for(auto& a:ans) cin >> a;
    cout << foo(0, 0,0);
}
