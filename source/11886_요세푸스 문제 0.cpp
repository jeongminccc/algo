//
//  11886_요세푸스 문제 0.cpp
//  algo
//
//  Created by jm on 2020/09/18.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=1; i<=n; ++i) v.push_back(i);
    
    cout << "<";
    auto iter = v.begin() + (k-1);
    while(!v.empty()){
        cout << *iter;
        if(v.size() > 1) cout << ", ";
        
        v.erase(iter);
        iter--;
        for(int i=0; i<k; ++i){
            if(iter >= v.end()-1) iter = v.begin();
            else iter++;
        }
    }
    
    cout << ">";
}
