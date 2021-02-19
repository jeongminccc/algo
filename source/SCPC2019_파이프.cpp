//
//  SCPC2019_파이프.cpp
//  algo
//
//  Created by jm on 2020/08/20.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
double pipe[101], answer[101], temp[101];

double measureLength(){
    for(int i=0; i<N; i++){
        if(i==0) {answer[i] = 0; continue;} // 제일 큰거부터 넣음
        if(i % 2 == 1){ // 뒤에서부터 올것
            answer[i] = sqrt(pow(pipe[N-(i/2+1)] + pipe[i/2], 2) - pow(pipe[N-(i/2+1)] - pipe[i/2], 2)) + answer[i-1];
        }else{
            answer[i] = sqrt(pow(pipe[N-(i/2)] + pipe[i/2], 2) - pow(pipe[N-(i/2)] - pipe[i/2], 2)) + answer[i-1];
        }
    }
    return N%2 == 0 ? answer[N-1] + pipe[N/2] : answer[N-1] + pipe[N/2-1];
}

int main(int argc, char** argv)
{
    int T, test_case;
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
        cin >> N;
        memset(pipe, 0, sizeof(pipe));
        memset(answer, 0, sizeof(answer));
        memset(temp, 0, sizeof(temp));
        
        for(int i=0; i<N; i++){
            cin >> pipe[i];
        }
        memcpy(temp, pipe, sizeof(pipe));
        
        sort(pipe, pipe+N);
        
        double ans = measureLength();
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                swap(pipe[i], pipe[j]);
                ans = min(ans, measureLength());
                swap(pipe[i], pipe[j]);
            }
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << fixed;
        cout.precision(15);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; ++j){
                if(temp[i] == pipe[j]){
                    if(j < N/2+N%2){
                        cout << answer[j*2];
                    }else{
                        cout << answer[1+(N-j-1)*2];
                    }
                }
            }if(i != N-1) cout << endl;
        }
    }cout << endl;

    return 0;//Your program should return 0 on normal termination.
}
