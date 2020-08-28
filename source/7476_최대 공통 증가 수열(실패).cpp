//
//  7476_최대 공통 증가 수열(실패).cpp
//  algo
//
//  Created by jm on 2020/08/27.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int cache[501][501];

int main(){
    int M;
    
    cin >> M;
    vector<int> v1(M);
    for(auto& a:v1) cin >> a;
    
    cin >> M;
    vector<int> v2(M);
    for(auto& a:v2) cin >> a;
    
    int lastBigV1[501],lastBigV2[501], pos1 = 0, pos2=0, posOfV1[501], lastPos2=0;
    cout << "  "; for(int i=0; i<v2.size(); i++) cout << v2[i] << " "; cout << endl;
    
    lastBigV1[0] = -1e9; lastBigV2[0] = -1e9;
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
        for(int j=0; j<v2.size(); j++){
            if(v1[i] == v2[j]){
                if(v1[i] > lastBigV1[pos1]){
                    if(j < lastPos2){
                        cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
                        continue;
                    }
                    lastPos2 = j;
                    pos1++;
                    lastBigV1[pos1] = v1[i];
                    cache[i+1][j+1] = cache[i][j] + 1;
                    posOfV1[i] = pos1;
                }else{
                    auto it = lower_bound(lastBigV1, lastBigV1+pos1, v1[i]);
                    *it = v1[i];
                    cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
                    posOfV1[i] = (int)(it - lastBigV1);
                }
            }
            else cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
            cout << cache[i+1][j+1] << " ";
        }
        cout << endl;
    }
    
    cout << cache[v1.size()][v2.size()] << endl;
    vector<int> ans;
    cout << endl;
    for(int i=(int)v1.size()-1; i>=0; --i){
        if(posOfV1[i] == pos1){
            ans.push_back(v1[i]);
            pos1--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& a:ans) cout << a << " ";
    cout << endl;
    return 0;
}
