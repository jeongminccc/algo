//
//  9471_피사노 주기.cpp
//  algo
//
//  Created by jm on 2020/10/02.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
              
int main(){
    int t;
    cin >> t;
    while(t--){
        int caseNum;
        cin >> caseNum;
        cout << caseNum << " ";

        int m, a=0, b=1, cnt=1;
        cin >> m;
        while(1){
            int temp = a;
            a = b;
            b = (temp + b) % m;
            if(a == 0 && b == 1) break;
            cnt++;
        }
        
        cout << cnt << '\n';
    }

}
