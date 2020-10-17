//
//  13877_이건 무슨 진법이지?.cpp
//  algo
//
//  Created by jm on 2020/10/15.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, tPos;
    cin >> t;
    
    while(t--){
        cin >> tPos; cout << tPos << " ";
        string input, s;
        cin >> input;
        int n = stoi(input);
        input = to_string(n);
        
        s = input;
        reverse(s.begin(), s.end());
        
        long long ans=0;
        bool notEight = false;
        for(int i=0; i<s.size(); ++i){
            if(s[i] - '0' >= 8){
                cout << "0 ";
                notEight = true;
                break;
            }
            ans += (s[i] - '0') * pow(8, i);
        }
        if(!notEight) cout << ans << " ";
        
        cout << input << " ";
        
        ans=0;
        for(int i=0; i<s.size(); ++i)
            ans += (s[i] - '0') * pow(16, i);
        
        cout << ans << "\n";
    }
    
}

