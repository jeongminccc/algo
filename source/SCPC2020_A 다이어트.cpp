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
vector<ll> calA, calB;

int main(int argc, char** argv)
{
    int T, test_case, N, K;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        calA.clear(); calB.clear();
        cin >> N >> K;
        Answer = 0;
        ll input;
        for(int i=0; i<N; i++){  cin >> input; calA.push_back(input);}
        for(int i=0; i<N; i++){  cin >> input; calB.push_back(input);}
        sort(calA.begin(), calA.end());
        sort(calB.begin(), calB.end(), [](const ll &a, const ll &b){
            return a > b;
        });
        
        for(int i=0; i<K; i++){
            Answer = max(Answer, calA[i] + calB[(N-K)+i]);
        }
        
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
