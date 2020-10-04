//
//  11286_절댓값 힙.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

struct ST{
    int val;
    int absVal;
};

struct cmp{
    bool operator()(ST& a, ST& b){
        return a.absVal > b.absVal ? true : a.absVal < b.absVal ? false : a.val > b.val;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    
    priority_queue<ST, vector<ST>, cmp> pq;
    
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        
        if(a == 0){
            if(pq.empty()) cout << "0" << '\n';
            else{
                cout << pq.top().val << '\n';
                pq.pop();
            }
        }
        else {
            ST temp;
            temp.val = a;
            temp.absVal = abs(a);
            pq.push(temp);
        }
    }
}
