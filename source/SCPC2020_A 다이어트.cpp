//
//  SCPC2020_A 다이어트.cpp
//  algo
//
//  Created by jm on 2020/08/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll Answer;

int main(int argc, char** argv)
{
    int T, test_case, N, K;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        calA.clear(); calB.clear();
        cin >> N >> K;
        Answer = 0;
        vector<ll> calA(N), calB(N);
        for(int &a:calA) cin >> a;
        for(int &a:calB) cin >> a;
        
        sort(calA.begin(), calA.end());
        sort(calB.begin(), calB.end(), greater<int>());
        
        for(int i=0; i<K; i++){
            Answer = max(Answer, calA[i] + calB[(N-K)+i]);
        }
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
