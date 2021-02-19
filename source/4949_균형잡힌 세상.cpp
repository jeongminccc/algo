//
//  4949_균형잡힌 세상.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    while(1){
        string s;
        getline(cin, s);
        if(s == ".") break;
        
        char c[101];
        bool flag = false;
        int pos = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '(') {
                pos++;
                c[pos] = '(';
            }
            else if(s[i] == ')'){
                if(c[pos] != '(') {flag = true; break;}
                pos--;
            }
            else if(s[i] == '['){
                pos++;
                c[pos] = '[';
            }
            else if(s[i] == ']'){
                if(c[pos] != '[') {flag = true; break;}
                pos--;
            }
        }
        if(pos != 0 || flag) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}
