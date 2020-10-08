//
//  2630_색종이 만들기.cpp
//  algo
//
//  Created by jm on 2020/10/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int blue=0, white=0;
vector<vector<int>> a;

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

vector<int> solution(vector<vector<int>> arr) {
    a = arr;
    vector<int> answer;
    
    foo(0,0,arr.size());
    answer.push_back(blue);
    answer.push_back(white);
    
    return answer;
}
