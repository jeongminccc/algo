//
//  8_원주율외우기.cpp
//  algo
//
//  Created by jm on 2020/08/12.
//  Copyright © 2020 jm. All rights reserved.
//

// 완탐으로는 절대 불가능함.
// 1111222를 보자, 이 수열을 쪼갤 수 있는 방법은 두가지 {1111, 222}, {111, 1222}이다. 따라서 길이 7인 수열 이 n개 있으면 이렇게 쪼갤 수
// 있는 방법의 수는 2^n개가 되는데, 길이 10,000인 수열에는 길이 7인 수열이 1,428개가 들어갈 수 있다.

// 메모이제이션의 적용
// 첫 조각의 길이는 3,4,5 중 하나.
// 전체 문제의 최적해는 다음 세경우 중 가장 작은값이 된다.
// 길이 3인 조각의 난이도 +3글자 빼고 나머지 수열에 대한 최적해.
// 길이 4인 조각의 난이도 +4글자 빼고 나머지 수열에 대한 최적해.
// 길이 5인 조각의 난이도 +5글자 빼고 나머지 수열에 대한 최적해.
// 나머지 수열의 최적해를 구할 때 앞의 부분을 어떤 식으로 쪼갰는지는 중요하지 않다. -> 즉 최적 부분 구조가 성립한다.

// 조각의 난이도를 판정하는것을 번거롭지만 어렵거나 시간이 오래 걸리는 작업은 아니다.
// 따라서 효율성보다는 구현의 용이성과 간결함에 초점을 맞춰 구현하는 것이 좋다.

const int INF = 987654321;
string N;
int classify(int a, int b){
    string M = N.substr(a, b-a+1);
    if(M == string(M.size(), M[0])) return 1;
    
    bool progressive = true;
    for(int i=0; i<M.size()-1; ++i)
        if(M[i+1] - M[i] != M[1] - M[0]) progressive = false;
    
    if(progressive && abs(M[1] - M[0]) == 1) return 2;
    
    bool alternating = true;
    for(int i=0; i<M.size(); ++i)
        if(M[i] != M[i%2])
            alternating = false;
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}

int cache[10002];
int memorize(int begin){
    if(begin == N.size()) return 0;
    
    int& ret = cache[begin];
    if(ret != -1) return ret;
    ret = INF;
    for(int L=3; L<=5; ++L){
        if(begin + L <= N.size())
            ret = min(ret, memorize(begin+L) + classify(begin, begin+L-1));
    }
    return ret;
}
