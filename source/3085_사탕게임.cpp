//
//  3085_사탕게임.cpp
//  algo
//
//  Created by jm on 2020/07/13.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int maxsum, col;

int check(char arr[][51]){
    int maxTemp=0;
    
    for(int i=0; i<col; i++){
        int sum=1;
        for(int j=0; j<col-1; j++){
            if(arr[i][j] == arr[i][j+1]) sum++;
            else sum = 1;
            maxTemp = max(maxTemp, sum);
        }
    }
    for(int j=0; j<col; j++){
        int sum2=1;
        for(int i=0; i<col-1; i++){
            if(arr[i][j] == arr[i+1][j]) sum2++;
            else sum2 = 1;
            maxTemp = max(maxTemp, sum2);
        }
    }
    return maxTemp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char arr[51][51];
    int ans=0;
    
    cin >> col;
    for(int i=0; i<col; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<col; i++){
        for(int j=0; j<col; j++){
            if(j != col-1){
                swap(arr[i][j], arr[i][j+1]);
                ans = max(ans,check(arr));
                swap(arr[i][j], arr[i][j+1]);
            }
            if(i != col-1){
                swap(arr[i][j], arr[i+1][j]);
                ans = max(ans,check(arr));
                swap(arr[i][j], arr[i+1][j]);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
