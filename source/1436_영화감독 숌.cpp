//
//  1436_영화감독 숌.cpp
//  algo
//
//  Created by jm on 2020/09/18.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int cnt = 0, pos=1;
    while (1) {
        string s = to_string(pos);
        if(s.find("666") != string::npos) cnt++;
        if(cnt == n){
            cout << pos;
            break;
        }
        pos++;
    }
}
