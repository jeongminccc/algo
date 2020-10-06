//
//  1620_나는야 포켓몬 마스터 이다솜.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    map<string,int> mStr; // unordered_map이 더 효율적
    map<int,string> mIdx; // string 배열이 더 효율적
    for(int i=1; i<=N; ++i){
        cin >> mIdx[i];
        mStr[mIdx[i]] = i;
    }
    
    while(M--){
        string ipt;
        cin >> ipt;
        if(ipt[0] < 'A' || ipt[0] > 'Z') cout << mIdx[stoi(ipt)] << '\n';
        else cout << mStr[ipt] << '\n';
    }
}
