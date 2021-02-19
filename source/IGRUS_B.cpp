//
//  IGRUS_B.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cnt=0;
    if(n == 0){ cout << "1"; return 0; }
    else if(n < 0){ cout << "32"; return 0;}
    while(n){
        n = n >> 1;
        cnt++;
    }
    cout << cnt;
    
}

