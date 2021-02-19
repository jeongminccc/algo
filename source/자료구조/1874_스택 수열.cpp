//
//  1874_스택 수열.cpp
//  algo
//
//  Created by jm on 2020/09/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, top=1;
    cin >> n;
    bool chk[100001] = {false};
    vector<int> v = {1};
    vector<char> ans = {'+'};
    chk[1] = true; chk[0] = true;
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        while(top <= a){
            if(!chk[top]){
                v.push_back(top);
                ans.push_back('+');
                chk[top] = true;
            }
            top++;
        }
        if(top != a){
            cout << "NO";
            return 0;
        }
        
        ans.push_back('-');
        v.pop_back();
        if(v.size() == 0) top = 0;
        else top = v.back();
    }
    
    for(auto&a:ans) cout << a << "\n";
}

