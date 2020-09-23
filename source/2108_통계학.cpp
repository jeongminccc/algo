//
//  2108_통계학.cpp
//  algo
//
//  Created by jm on 2020/09/23.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum=0, mostValue[8001] = {0}, mostV=0, mostI=0;
    vector<int> midValue;
    cin >> n;
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        sum += input;
        midValue.push_back(input);
        mostValue[input+4000]++;
        
        if(mostV < mostValue[input+4000]){
            mostV = mostValue[input+4000];
        }
    }
    
    bool isSecond = false;
    for(int i=0; i<=8000; ++i){
        if(mostV == mostValue[i]){
            if(isSecond){
                mostI = i - 4000;
                break;
            }
            isSecond = true;
            mostI = i - 4000;
        }
    }
    sort(midValue.begin(), midValue.end());
    
    cout << round(sum / (double)n) << endl;
    cout << midValue[n/2] << endl;
    cout << mostI << endl;
    cout << abs(midValue[0] - midValue[n-1]) << endl;
}

