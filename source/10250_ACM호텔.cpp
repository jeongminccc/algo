//
//  10250_ACM호텔.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int h,w,n,ans=1;
        cin >> h >> w >> n;
        
        ans += (n-1) / h;
        if(n%h == 0) ans += h * 100;
        else ans += (n%h) * 100;
        cout << ans << '\n';
    }
}
