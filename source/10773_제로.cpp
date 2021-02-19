//
//  10773_제로.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int k;
    cin >> k;
    deque<int> dq;
    for(int i=0; i<k; ++i){
        int input;
        cin >> input;
        if(input == 0) dq.pop_back();
        else dq.push_back(input);
    }
    
    int ans=0;
    while (!dq.empty()) {
        ans += dq.front();
        dq.pop_front();
    }
    cout << ans << endl;
}
