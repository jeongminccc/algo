//
//  7568_덩치.cpp
//  algo
//
//  Created by jm on 2020/09/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int n;
    cin >> n;
    int arr[51][2];
    for(int i=0; i<n; ++i) cin >> arr[i][0] >> arr[i][1];
    
    for(int i=0; i<n; ++i){
        int cnt=1;
        for(int j=0; j<n; ++j)
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) cnt++;
        
        cout << cnt << endl;
    }
}
