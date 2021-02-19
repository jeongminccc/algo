//
//  2630_색종이 만들기.cpp
//  algo
//
//  Created by jm on 2020/10/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int arr[150][150], blue=0, white=0;

void foo(int x, int y, int size){
    
    int b_cnt=0;
    for(int i=x; i<x+size; ++i)
        for(int j=y; j<y+size; ++j)
            if(arr[i][j]) b_cnt++;
    
    if(!b_cnt) white++;
    else if(b_cnt == size * size) blue++;
    else{
        foo(x, y, size/2);
        foo(x, y + size/2, size/2);
        foo(x + size/2, y, size/2);
        foo(x + size/2, y + size/2, size/2);
    }
    
    return;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> arr[i][j];
    
    foo(0,0,n);
    cout << white << " " << blue;
}

