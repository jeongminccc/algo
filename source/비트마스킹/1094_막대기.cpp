//
//  1094_막대기.cpp
//  algo
//
//  Created by jm on 2020/09/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, cnt=0;
    cin >> a;
    while(a){
        cnt += a & 1;
        a /= 2;
    }
    
    cout << cnt;
}

// 23인 경우
// 64 -> 32, 32
// 32 -> 16, 16
// 16, 16 -> 8, 8, 16
// 8, 16 -> 4, 4, 16
// 4, 4, 16 -> 2, 2, 4, 16
// 2, 2, 4, 16 -> 1, 1, 2, 4, 16
