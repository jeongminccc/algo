//
//  3040_백설공주와 일곱난장이.cpp
//  algo
//
//  Created by jm on 2020/09/23.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[9], bit[9]={0,0,1,1,1,1,1,1,1};
    for(int i=0; i<9; ++i) cin >> a[i];
    
    vector<int> v;
    do{
        int ans=0;
        for(int i=0; i<9; ++i) if(bit[i]) ans += a[i];
        
        if(ans == 100)
            for(int i=0; i<9; ++i)
                if(bit[i]) v.push_back(a[i]);
    }while(next_permutation(bit, bit+9));
    
    sort(v.begin(), v.end());
    for(auto&a:v) cout << a << endl;
}

