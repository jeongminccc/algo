//
//  2164_카드2.cpp
//  algo
//
//  Created by jm on 2020/09/23.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=n; i>=1; --i) dq.push_back(i);
    
    bool flag = true;
    while(dq.size() > 1){
        if(flag){
            dq.pop_back();
            flag = false;
        }else{
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            flag = true;
        }
    }
    cout << dq.front();
}

