//
//  8_someObscureFunction.cpp
//  algo
//
//  Created by jm on 2020/07/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

// 이항계수의 계산을 재귀 호출로 하는것보다 메모이제이션을 이용하면 훨씬 빠르다.
// 메모이제이션은 참조적 투명성(입력이 고정되어있을때 결과가 항상같은것)의 경우에만 적용가능함.
// 적용가능하지않은경우 -> int counter = 0; int count(){ return counter++; } -> 함수종료후에도 값이 유지
// 메모이제이션 구현 패턴을 정해놓자.
// 시간 복잡도는 (존재하는 부분 문제의 수) X (한 부분 문제를 풀 때 필요한 반복문의 수행 횟수)

int cache[2500][2500];

int someObscureFunction(int a, int b){
//    기저사례 처리
    if(...) return ...;
//    (a,b)에 대한 답을 구한 적이 있으면 곧장 반환
    int& ret = cache[a][b];
    if(ret != -1) return ret;
//    여기에서 답을 계산.
//    ...
    return ret;
}

int main(){
//  memset()을 이용해 cache배열을 초기화한다.
    memset(cache, -1, sizeof(cache));
}
