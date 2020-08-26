//
//  13701_중복제거.cpp
//  algo
//
//  Created by jm on 2020/08/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int a[(1<<20)];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    char c;
    do{
        cin >> n;
        int x = n/32;
        int y = n%32;
        if(!(a[x] & (1<<y))) {
            cout << n << " ";
            a[x] |= (1<<y);
        }
    }while((c = cin.get()) == ' ');
    
    return 0;
}

