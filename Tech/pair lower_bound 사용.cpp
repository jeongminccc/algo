//
//  pair lower_bound 사용.cpp
//  algo
//
//  Created by jm on 2020/09/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int, int>& b){
    return a.second < b.second;
}

int main(){
    vector<pair<int,int>> a = {{1,2}, {2,3}, {3,7}, {8,1}};
    
    sort(a.begin(), a.end(), cmp);
    
    for(auto& x:a) cout << x.first << " " << x.second << endl;
    auto iter = lower_bound(a.begin(), a.end(), make_pair(0,3), cmp);
    
    cout << (*iter).first << " " << (*iter).second;
    return 0;
}
