//
//  8_Quantiztion.cpp
//  algo
//
//  Created by jm on 2020/08/13.
//  Copyright © 2020 jm. All rights reserved.
//

// 이 문제는 재귀호출(quantize(A) = A에 속한 수를 양자화해서 얻을 수 있는 최소 오차 제곱의 합)로 해결하기에는,
// 사용할 수 있는 숫자의 가짓수에 제한이 있기 때문에 최적 부분 조건이 성립하지 않는다.
// 결국 quantize(A,U) = U가 지금까지 한번 이상 사용한 숫자들의 집합일 때 A에 속한 수를 양자화 해서 얻을수 있는 최소.
// 하지만 이 완탐 코드는, 원본수열 수의 범위가 1000까지이므로 U의 크기가 10인 경우에만도 1000C10개의 부분 문제가 존재한다.
// 즉 메모이제이션에 필요한 메모리를 확보할 수 없는것은 물론, 시간도 느리다.

// 답의 형태 제한하기
// 이와 같이 부분 문제 개수가 너무 많을때 시도할 수 있는 방법은 많은데,
// 그중 답이 항상 어떤 구조를 가질 것이라고 예측하고 그것을 강제하는 방법이 있다.
// 주어진 수열을 정렬하면, 같은 숫자로 양자화 되는 숫자들은 항상 인접해 있다!!
// 따라서 이 문제는 주어진 수열을 s개의 묶음으로 나누는 문제가 된다.
// 매 재귀 호출마다 첫 묶음의 크기가 얼마일지를 결정하면 된다.
// 이떄 나머지 묶음의 오류 합이 최소여야 전체도 최소 오류이기 때문에 최적 부분 구조 또한 성립하는것을 알수 있다.
// 여기서 만든 점화식 quantize()는 이전 묶음에대한 정보들을 전혀 입력받지 않으므로, 최적 부분 조건이 성립함을 알수 있다.

const int INF = 987654321;
// A[] : 양자화해야 할 수열, 정렬한 상태
// pSum[] : A[]의 부분합을 저장한다. pSum[i]는 A[0] .. A[i]의합
// pSqSum[] : A[]제곱의 부분합을 저장한다. pSqSum[i]는 A[0]^2 .. A[i]^2의 합
int n;
int A[101], pSum[101], pSqSum[101];
void precalc(){
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i=1; i<n; ++i){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}
// 하나의 구간에대한 최소 오차 합 계산
int minError(int lo, int hi){
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
    // 평균을 반올림한 값으로 이 수들을 표현한다.
    int m = int(0.5 + (double)sum / (hi - lo +1));
    // sum (A[i]-m)^2를 전개한 결과를 부분 합으로 표현
    int ret = sqSum - 2 * m * sum * m * m * (hi-lo+1);
    return ret;
}
int cache[101][11];
int quantize(int from, int parts){
    if(from == n) return 0;
    if(parts == 0) return INF;
    
    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;
    for(int partSize = 1; from + partSize <= n; ++partSize){
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts-1));
    }
    return ret;
}
