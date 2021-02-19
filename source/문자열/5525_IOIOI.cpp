//
//  5525_IOIOI.cpp
//  algo
//
//  Created by jm on 2020/10/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, size;
    cin >> n >> size;
    n = n * 2 + 1;
    
    string s, ans="", patturn = "IOI";
    for(int i=0; i<n; ++i){
        if(i % 2 == 0) ans += 'I';
        else ans += 'O';
    }
    cin >> s;
    bool start = false;
    int cnt=0;
    for(int i=0; i<s.size();){
        if(!start && s[i] == 'I'){ // ans와 같은지 체크
            int j;
            for(j=0; j<n && i+j < s.size(); ++j)
                if(s[i+j] != ans[j]) break;
            
            if(j == n) {start = true; cnt++; i += n-1;}// 같음
            else i += j;
        }
        else if(start){
            int j;
            for(j=0; j<3 && i+j < s.size(); ++j)
                if(s[i+j] != patturn[j]) break;
            
            if(j == 3) {i += 2; cnt++;}
            else {
                start = false;
                i += j;
            }
        }
        else i++;
    }
    
    cout << cnt;
}

