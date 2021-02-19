//
//  1377_버블 소트.cpp
//  algo
//
//  Created by jm on 2020/10/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    pair<int,int> a[500001] ={{0,0}};
    cin >> n;
    
    for(int i=0; i<n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a, a+n);
    
    int ret=0;
    for(int i=0; i<n; ++i)
        ret = max(ret, a[i].second - i);
    
    cout << ret + 1;
}
