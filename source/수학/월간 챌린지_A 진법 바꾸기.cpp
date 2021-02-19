//
//  월간 챌린지_A 진법 바꾸기.cpp
//  algo
//
//  Created by jm on 2020/10/08.
//  Copyright © 2020 jm. All rights reserved.
//
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

int three(int n){
    vector<int> v;

    while (1) {
        v.push_back(n%3);
        n /= 3;
        if (n == 0) break;
    }
    reverse(v.begin(), v.end());
    
    int ret = 0, pos=1;
    for(int i=0; i<v.size(); ++i){
        ret += pos * v[i];
        pos *= 3;
    }
    
    return ret;
}

int solution(int n) {
    int answer = 0;
    
    answer = three(n);
    return answer;
}

