//
//  11279_최대 힙.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<>> pq;
    
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
