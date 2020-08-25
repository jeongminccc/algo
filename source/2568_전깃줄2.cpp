//
//  2568_전깃줄2.cpp
//  algo
//
//  Created by jm on 2020/08/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 500000 + 1;

pair<int,int> arr[MAX];
int dp[MAX], arrIndex[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr+N, [](pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first;
    });

    int pos=1;
    dp[0] = arr[0].second; arrIndex[1] = 1;
    for(int i=1; i<N; i++){
        if(arr[i].second > dp[pos-1]){
            dp[pos] = arr[i].second;
            pos++;
            arrIndex[arr[i].first] = pos;
        }else{
            auto it = lower_bound(dp, dp+pos, arr[i].second);
            *it = arr[i].second;
            arrIndex[arr[i].first] = int(it - dp) + 1;
        }
    }
    
    vector<int> ansList;
    cout << N-pos << endl;
    for(int i=arr[N-1].first; i>0; --i){
        if(arrIndex[i] == pos && pos > 0) {ansList.push_back(i); pos--;}
    }
    
    int temp = int(ansList.size()-1);
    for(int i=0; i<N; ++i){
        if(arr[i].first != ansList[temp]) cout << arr[i].first << ';
        else temp--;
    }
    return 0;
}

