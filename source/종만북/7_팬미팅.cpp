//
//  7_팬미팅.cpp
//  algo
//
//  Created by jm on 2020/07/24.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int hugs(const string& members, const string& fans){
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    
    for(int i=0; i<N; ++i) A[i] = (members[i] == 'M');
    for(int i=0; i<M; ++i) B[M-i-1] = (fans[i] == 'M');
    
    vector<int> C = karatsuba(A, B);
    int allHugs = 0;
    for(int i= N-1; i < M; ++i){
        if(C[i] == 0)
            ++allHugs;
    }
    return allHugs;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    string members, fans;
    cin >> n >> members >> fans;
    
    n = hugs(members, fans);
}
