//
//  8_폴리오미노.cpp
//  algo
//
//  Created by jm on 2020/08/27.
//  Copyright © 2020 jm. All rights reserved.
//

// 정사각형들의 변들을 서로 완전하게 붙여 만든 도형들을 폴리오미노라 한다.
// 세로로 단조(monotone)인 폴리오미노의 개수를 세자. -> 어떤 가로줄도 폴리오미노를 두번 이상 교차하지 않는다는 뜻.

// ---- 완탐부터 시작하자
// 어떤 순서대로 정사각형들을 붙여나갈건지 결정하는 것이 중요.
// 모든 폴리오미노들을 첫번째 가로줄에 포함된 정사각형의 수를 기준으로 분류하자.
// poly(n) = n개의 정사각형으로 만들수 있는 세로단조 폴리오미노의 수

// 하지만 이조차도 모든것을 구분할 순 없기에,
// poly(n,first) = n개의 정사각형을 포함하되, 첫 줄에 first개의 정사각형이 들어가는 폴리오미노의 수라 하자.
// 즉 poly(n-first, 1) + poly(n-first, 2) + ... + poly(n-first, n-first)로 구할 수 있다.
// 이때 두 번째 줄에 있는 정사각형의 수에 따라 이들을 붙일 수 있는 방법의 수가 정해진다.
// -> 첫 줄에 first개의 정사각형이 있고, 나머지 사각형ㅇ로 만든 폴리오미노의 첫줄에 second개의 정사각형이 있다고 할때 이들을 붙일수 있는 방법의 수는 first + second - 1이다.
// 즉 first x poly(n-first,1) + (first+1) x poly(n-first,2) + ... + (n-1) x poly(n-first, n-first) 가 되낟.

const int MOD = 10*1000*1000;
int cache[101][101];
int poly(int n, int first){
    if(n == first) return 1;
    
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    ret = 0;
    for(int second = 1; second <= n-first; ++second){
        int add = second + first - 1;
        add *= poly(n-first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}
// 시간복잡도 - 가능한 n과 first의 조합의 수는 O(n^2)이고, poly()한번 계산하는데에 O(n)이므로 O(n^3)이다.
