//
//  2292_벌집.cpp
//  algo
//
//  Created by jm on 2020/09/23.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = 1, cnt=1, i=0;
    while(ans < n){
        cnt++;
        i++;
        ans += (i*6);
    }
    cout << cnt;
}

// 1, 7,  19, 37, 61
//   6  12  18  24
