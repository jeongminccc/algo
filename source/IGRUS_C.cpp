//
//  IGRUS_C.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    
    for(int i=64; i>=0; --i){
        if(n % 2 ){
            cout << i;
            return 0;
        }
        n /= 2;
    }
}

