//
//  1541_잃어버린 괄호.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[50], N=0, ans=0;
    bool flag=false;
    
    while(true){
        cin >> arr[N];
        if(cin.eof() || arr[N] == 0) break;
        
        if(arr[N] < 0) flag = true;
        
        if(flag) ans -= abs(arr[N]);
        else ans += arr[N];
        
        N++;
    }
    cout << ans;
}
