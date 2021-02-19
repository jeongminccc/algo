//
//  1966_프린터큐.cpp
//  algo
//
//  Created by jm on 2020/09/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, pic;
        cin >> n >> pic;
        vector<int> v(n);
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            q.push({v[i],i});
        }

        sort(v.begin(), v.end());
        int cnt=0;
        while(!q.empty()){
            int tmp = q.front().first;
            int idx = q.front().second;
            q.pop();
            
            if(tmp < v.back()){
                q.push({tmp,idx});
            }else{
                v.pop_back();
                cnt++;
                if(idx == pic){
                    cout << cnt << '\n';
                    break;
                }
            }
        }
    }
}
