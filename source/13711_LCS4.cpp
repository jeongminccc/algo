//
//  13711_LCS4.cpp
//  algo
//
//  Created by jm on 2020/08/25.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000 + 1;

int a[MAX], b[MAX];
int order[MAX];
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
    for (int j = 1; j <= n; j++){
        order[b[j]] = j;
    }
    for (int i = 1; i <= n; i++){
        a[i] = order[a[i]];
        cout << a[i] << " " ;
    }cout << endl;

    int ans = 0;
    vector<int> v; v.push_back(-1);
    for (int i = 1; i <= n; i++){ cout << order[i] << " ";
        if (v.back() < a[i]){
            v.push_back(a[i]); ans++;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            *it = a[i];
        }
    }
    cout << ans;
}
