//
//  8_경우의 수와 확률.cpp
//  algo
//
//  Created by jm on 2020/08/13.
//  Copyright © 2020 jm. All rights reserved.
//

// DP는 최적화 문제를 풀기 위해 고안되었긴 했지만, 경우의 수를 세거나 확률을 계산하는 문제에도 흔하게 사용된다.
// 경우의 수 계산 문제는 흔히 재귀적인 특징을 가지고있기 떄문이다(ex 이항계수)

// 오버플로에 유의하기
// 대개 경우의 수를 세는 문제에서 답은 입력의 크기에 대해 지수적으로 증가하기 마련이다. - 그렇지않다면 그냥 완탐쓰면 되므로
// 즉 답이 보통 32비트 정수형보다 크게 나오는 경우가 많다. (그래서 M으로 나눈 나머지 출력하라함)

// ---------------- 타일링 방법의 수 세기 -------------- //

// 먼저 완탐을 이용한 함수를 작성한뒤, 메모이제이션을 이용해 DP로 바꿔보자.
// 맨 왼쪽 세로줄이 어떻게 채워져 있느냐에 따라 나눌 수 있다 (세로한줄 or 두개의 가로타일)
// 이때, 다음의 조건들이 성립함을 알 수 있다.
// - 이 두 가지 분류는 타일링 하는 방법을 모두 포함합니다. -> 모든 방법 포함 (이 조건을 위반시 실제보다 적은 답 출력)
// - 두 가지 분류에 모두 포함되는 타일링 방법은 없습니다.  -> 중복 아님     (이 조건을 위반시 실제보다 많은 답 출력)
// 이 두가지 속성은 경우의 수를 셀때 항상 확인해야 하는 조건이다.

// 부분 문제 정의 : tiling(n) = 2 x n 크기의 사각형을 타일로 덮는 방법을 반환한다.
// 이전의 정보는 들어가있지 않음.
// 세로타일 하나 혹은 가로타일 두개이므로, 즉 tiling(n) = tiling(n-1) + tiling(n-2)가 성립함을 알 수 있다.

// DP code
const int MOD = 1000000007;
int cache[101];
int tiling(int width){
    if(width <= 1) return 1;
    
    int& ret = cache[width];
    if(ret != -1) return ret;
    return ret = (tiling(width-1) + tiling(width-2)) % MOD;
}
// 부분문제수는 O(n)이고, 계산에는 O(1)의 시간이 들기때문에 전체 시간복잡도는 O(n)


// ---------------- 삼각형 위의 최대 경로 개수 세기 -------------- //

// 이전문제에서는 최대경로의 합만 구했고, 경로 자체는 구하지 않았다.
// 이 문제를 해결하기 위해서는 두개의 다른 DP를 해결해야 한다.
// 먼저 바탕이 되는 최적화 문제를 푼 뒤, 각 부분 문제마다 최적해의 개수를 계산하는 DP 알고리즘을 만드는 것이다.
// 먼저 최적화 문제는 앞에서 풀었기 때문에, 최대 합이 기록되어 있는 배열에서, 합이 더 높은 경로로 내려가는 방식의 알고리즘으로
// 최대 경로의 개수를 센다.

int countCache[100][100];
int count(int y, int x){
    if(y == n-1) return 1;
    
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    
    if(count(y+1,x) >= count(y+1,x+1)) ret += count(y+1,x);
    if(count(y+1,x) <= count(y+1,x+1)) ret += count(y+1,x+1);
    return ret;
}


// ---------------- 우물을 기어오르는 달팽이 -------------- //

// 확률과 경우의 수에는 밀접한 관련이 있기 때문에 많은 경우 확률을 계산하는 문제에도 DP를 쓸 수 있다.
// 깊이가 n미터, 달팽이는 비가내리면 2미터, 안내리면 1미터 올라간다. m일간 50%확률로 비가온다고 가정하면 우물끝까지 올라갈 확률은?
//
