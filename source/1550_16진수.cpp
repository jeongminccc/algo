//
//  1550_16진수.cpp
//  algo
//
//  Created by jm on 2020/09/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ans=0;
    for(int i=0; i<s.size(); ++i){
        if(s[s.size()-i-1] <= '9') ans += (s[s.size()-i-1] - '0') * pow(16,i);
        else ans += (s[s.size()-i-1] - 'A' + 10) * pow(16,i);
    }
    
    cout << ans;
}
