//
//  1371_가장 많은 글자.cpp
//  algo
//
//  Created by jm on 2020/10/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int alpa[26]={0};
    
    while(1){
        string s;
        cin >> s;
        if(cin.eof()) break;
        
        for(char& c:s) alpa[c - 'a']++;
    }
    int ret=0;
    vector<char> ans;
    for(int i=0; i<26; ++i){
        if(ret < alpa[i]){
            ans = {(i + 'a')};
            ret = alpa[i];
        }else if(ret == alpa[i])
            ans.push_back(i + 'a');
    }
    
    for(char&c:ans) cout << c;
}
