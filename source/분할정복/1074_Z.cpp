//
//  1074_Z.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int n,r,c,cnt=0;

void foo(int x, int y, int n, int cnt){
    if(x == r && y == c) {
        cout << cnt;
        return;
    }
    
    if(n==0) return;
    else{
        if(r < x + pow(2,n)/2 && c < y + pow(2,n)/2)
            foo(x, y, n-1, cnt);
        else if(r < x + pow(2,n)/2)
            foo(x, y + pow(2,n)/2, n-1, cnt + pow(2,n-1) * pow(2,n-1));
        else if(c < y + pow(2,n)/2)
            foo(x + pow(2,n)/2, y, n-1, cnt + pow(2,n-1) * pow(2,n-1) * 2);
        else
            foo(x + pow(2,n)/2, y + pow(2,n)/2, n-1, cnt + pow(2,n-1) * pow(2,n-1) * 3);
    }
}

int main(){
    cin >> n >> r >> c;
    foo(0,0,n,0);
}
