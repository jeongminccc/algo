//
//  1264_모음의 개수.cpp
//  algo
//
//  Created by jm on 2020/10/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    while(1){
        string s;
        map<char, int> m;
        getline(cin ,s);
        if(s == "#") break;
        
        for(auto& a:s){
            char c = a;
            if(c < 'a') c += 32;
            
            m[c]++;
        }
        cout << m['a'] + m['i'] + m['u'] + m['e'] + m['o'] << '\n';
    }
}
