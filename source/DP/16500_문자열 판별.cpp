//
//  16500_문자열 판별.cpp
//  algo
//
//  Created by jm on 2020/08/30.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

string S, A[101];
bool check[101][101] ={false};
bool ans = false;
int N;

void isPossible(string a, int cnt){
    if(a.length() >= S.length() || cnt > S.length()){
        if(a==S) ans = true;
        return;
    }
    if(check[a.length()][cnt]) return;
    check[a.length()][cnt] = true;
    
    isPossible(a, cnt+1);
    for(int i=0; i<N; i++){
        if(a + A[i] == S.substr(0, a.length() + A[i].length()))
            isPossible(a + A[i], cnt+1);
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> S >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    isPossible("", 0);
    
    cout << ans << endl;
    return 0;
}
