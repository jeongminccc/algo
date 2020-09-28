//
//  IGRUS_A.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(m == 1 || m == 2) cout << "NEWBIE!";
    else if(n >= m) cout << "OLDBIE!";
    else cout << "TLE!";
}
