//
//  1259_펠린드롬 수.cpp
//  algo
//
//  Created by jm on 2020/09/18.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    while(1){
        string s;
        cin >> s;
        if(s == "0") break;
        
        string temp = s;
        reverse(s.begin(), s.end());
        if(s == temp) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
