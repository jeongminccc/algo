//
//  17072_아스키아트.cpp
//  algo
//
//  Created by jm on 2020/08/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, A, ans = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M*3; j++){
            cin >> A;
            if(j%3 == 0) ans += 2126 * A;
            else if(j%3 == 1) ans += 7152 * A;
            else{
                ans += 722 * A;
                if(0 <= ans && ans < 510000) cout << "#";
                else if(ans < 1020000) cout << "o";
                else if(ans < 1530000) cout << "+";
                else if(ans < 2040000) cout << "-";
                else cout << ".";
                ans = 0;
            }
        }cout << "\n";
    }
    return 0;
}

