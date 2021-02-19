//
//  1927_최소 힙.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        
        if(num == 0){
            if(pq.empty()) cout << "0" << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(num);
    }
}
