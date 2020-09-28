//
//  IGRUS_E.cpp
//  algo
//
//  Created by jm on 2020/09/28.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int keyboard[26];

int main(){
    string s, title ="";
    getline(cin ,s);

    int space;
    cin >> space;

    for(int i=0; i<26; ++i) cin >> keyboard[i];

    char before = '=';
    bool flag = true;
    for(int i=0; i<s.size(); ++i){
        if(s[i] == ' '){
            flag=true;
            if(before == s[i]) continue;
            space--;
            before = ' ';
        }
        else{
            if(flag){
                title += s[i];
                flag=false;
            }
            
            if(s[i] == before) continue;
            else{
                before = s[i];
                if(s[i] < 'a') s[i] = s[i] - 'A' + 'a';
                keyboard[s[i] - 'a']--;
            }
        }
    }
    
    transform(title.begin(), title.end(), title.begin(), ::toupper);
    before = ' ';
    for(int i=0; i<title.size(); ++i){
        if(title[i] == before) continue;
        else{
            before = title[i];
            keyboard[title[i] - 'A']--;
        }
    }
    
    for(int i=0; i<26; ++i){
        if(keyboard[i] < 0 || space < 0){
            cout << -1;
            return 0;
        }
    }
//    for(int i=0; i<26; ++i) cout << keyboard[i] << " ";
    cout << title;
}

