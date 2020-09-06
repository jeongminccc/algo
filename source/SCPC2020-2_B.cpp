//
//  SCPC2020-2_B.cpp
//  algo
//
//  Created by jm on 2020/09/05.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAX = 300001;

int N;
ll Answer, M;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T, test_case;
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cin >> N >> M;
        Answer = 0;
        set<ll> sweetpotato;
        ll sum = 0;
        sweetpotato.insert(0);
        for(int i=0; i<N; i++) {
            ll input;
            cin >> input;
            sum += x;
            sweetpotato.insert(sum);
            ll search = *S.lower_bound(sum-M);
            Answer = max(ans, sum-search);
        }
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
