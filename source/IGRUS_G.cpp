//
//  IGRUS_G.cpp
//  algo
//
//  Created by jm on 2020/09/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    double x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    
    double distance = sqrt(pow(x2-x1,2) + pow(y2-y1, 2) + pow(z2-z1, 2));
    
    int n, sum=0;
    cin >> n;
    vector<int> bar(n);
    for(int i=0; i<n; ++i) {
        cin >> bar[i];
        sum += bar[i];
    }
    
    sort(bar.begin(), bar.end(), greater<>());
    
    if(bar[0] <= distance){
        if(sum >= distance) cout << "YES";
        else cout << "NO";
    }
    else{
        if(bar[0] - distance <= sum - bar[0]) cout << "YES";
        else cout << "NO";
    }
}

