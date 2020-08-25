//
//  8_최대 증가 부분 수열.cpp
//  algo
//
//  Created by jm on 2020/07/31.
//  Copyright © 2020 jm. All rights reserved.
//

// 매우 유명한 DP 연습문제임.
// 완전 탐색부터 시작해보자. 문제를 숫자 하나씩으로 조각낸 뒤, 한 조각에서 숫자 하나씩을 선택하는 완탐 알고리즘을 만들면
// 수열 A를 입력 받아 LIS의 길이를 반환하는 재귀 함수 lis(A)는, A의 모든 증가 부분 수열을 만든 뒤 가장 긴것의 길이를 반환.
// lis(A)는 수열의 첫 번째 수를 고르고 나머지 부분을 재귀적으로 만들것이다.
// A[j] 보다 큰 숫자들만 고른 부분 수열 B를 만들고 B의 LIS를 재귀 호출로 계산한다.
// B에서 얻은 LIS를 A[j]뒤에 붙이면, A[j]로 시작하는 LIS를 얻을수 있다. -> 최적 부분 구조가 성립함을 알 수 있음.

// 완전탐색 알고리즘
int lis(const vector<int>& A){
    // 기저사례 : A가 텅 비어 있을때
    if(A.empty()) return 0;
    int ret = 0;
    for(int i=0; i<A.size(); ++i){
        vector<int> B;
        for(int j=i+1; j<A.size(); ++j)
            if(A[i] < A[j])
                B.push_back(A[j]);
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}
// 이 코드는 메모이제이션을 적용하기 까다롭다. 입력이 정수가 아니라 정수의 배열이기 떄문.
// map같은 연관 배열을 써서 메모이제이션을 해도 되지만 엄청 느리므로 최후의 수단으로 남겨둔다.
// 어떻게 하면 A를 좀 더 간단하게 표현할까? -> 항상 두가지 중 하나이다.
// 1. 원래 주어진 수열 S
// 2. 원래 주어진 수열의 원소 S[i]에 대해, S[i+1,,,] 부분 수열에서 S[i]보다 큰 수들만을 포함하는 부분 수열 - 이전에 선택한 수들이 정의에 포함되지 않음
// 이전에 선택된 수들은 어차피 마지막에 선택된 수보다 전에 있고 더 작기 때문에, 이들 보다 뒤에있고 커야 한다는 조건은 2번 조건만으로 모두 만족된다.
// 2번 정의에 포함되는 A는 S의 인덱스와 1:1 대응 된다는 점입니다. A로 주어질 수 있는 입력은 전부 N+1가지 밖에 없다는 이야기이다.
// 그럼 부분 문제의 정의를, lis(start) = S[start]에서 시작하는 부분 증가 수열 중 최대의 길이로 바꾸면 어떨까?

// DP (1)
int n;
int cache[100], S[100];
int lis2(int start){
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1; // 항상 S[start]는 있으므로 길이는 최하 1
    for(int next = start+1; next < n; ++next)
        if(S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}
// 별도의 기저 사례 없이, 뒤에 더 이을 숫자가 없는 경우에도 for문을 순회한다.
// 총 O(n)개의 부분 문제를 갖고, O(n)시간의 반복문을 순회하므로 O(n^2)의 시간 복잡도를 갖는다.


// < 시작 위치 고정하기 >
// lis2()를 호출할 때는 항상 증가 부분 수열의 시작 위치를 지정해 줘야 하므로, 호출할때 각 위치를 순회하면서 최대 값을 찾는 형태의 코드작성해야함.
int maxLen = 0;
for(int begin = 0; begin < n; ++begin)
    maxLen = max(maxLne, lis2(begin));

// 또 다른 방법은, S[-1] = -무한 이라고 가정하는 코드를 작성하면, lis2(-1)을 호출하면 항상 -무한부터 시작하니까 모든 시작 위치를 자동으로 시도하게 된다.

// DP (2)
int n;
int cache[100], S[100];
int lis3(int start){
    int& ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next<n; ++next)
        if(start == -1 || S[start] < S[next])
            ret = max(ret, lis3(next) + 1);
    return ret;
}

// 더 빠른 해법
// O(nlgn)에 LIS를 찾을 수 있는 알고리즘이 있다.
// 텅 빈 수열에서 시작해 숫자를 하나씩 추가해 나가며 각 길이를 갖는 증가 수열 중 가장 마지막 수가 작은 것은 무엇인지를 추적한다.
// 예를 들어 [5,6,7,1,2] 일때, 이 부분 수열의 LIS는 길이가 3인 5,6,7 밖에 없지만, 2인 부분 증가수열은 5,6 5,7 1,2 의 세개가 있을수 있다.
// 이중 가장 유리한 것은 1,2이다. 다음 수로 3이나 4가 주어질 경우 1,2뒤에는 연결해서 길이 3인 원소를 만들 수 있는데, 5,6 뒤에는 연결할 수 없기 때문이다.
// 원소를 추가하는 과정에서 다음과 같은 배열을 유지하자. C[i] = 지금까지 만든 부분 배열이 갖는 길이 i인 증가 부분 수열 중 최소의 마지막 값
// 이렇게 코드를 개선하면 LIS의 길이 k에 대해 O(nk) 시간에 LIS를 찾을 수 있다.
// 한발짝 더 나아가 C[]가 항상 순증가 한다는 사실을 꺠닫고 나면, C[]에서 이분 검색을 함으로써 LIS를 O(nlgk) <= O(nlgn)에 찾는 알고리즘을 만들 수 있다.

// 최적화 문제 동적 계획법 레시피

// 1. 모든 답을 만들어 보고 그 중 최적해의 점수를 반환하는 완탐을 설계
// 2. 전체 답의 점수를 반환하는 것이 아니라, 앞으로 남은 선택들에 해당하는 점수들만 반환하도록 부분 문제 정의를 바꾼다.
// 3. 재귀 호출의 입력에 이전의 선택에 관련된 정보가 있다면 꼭 필요한 것만 남기고 줄인다. 문제에 최적 부분 구조가 성립할 경우에는 이전 선택에 관련된 정보를
// 완전히 없앨 수도 있다. 여기서 목표는 가능한 한 중복 되는 부분 문제를 많이 만드는 것. 입력의 종류가 줄어들면 줄어들 수록 더 많은 부분 문제가 중복되고,
// 따라서 메모이제이션을 최대 한도로 활용할 수 있다.
// 4. 입력이 배열이거나 문자열인 경우 가능하다면 적절한 변환을 통해 메모이제이션을 할 수 있도록 한다.
// 5. 메모이제이션을 적용.

// 삼각형 최대 경로 문제에 적용해보기
// 1. 모든 경로를 만들어 보고 전체 합 중 최대치를 반환하는 완탐 path1() 작성.
// 2. path1()이 전체경로의 최대합을 반환하는 것이 아니라, (y,x) 이후로 만난 숫자들의 최대 합만을 반환하도록 바꾼다.
// 3. 이렇게 바꿈으로써 sum을 입력받을 필요가 없어짐. 최적 부분 구조가 성립하기 때문.
// 4. 해당 안함 (LIS문제 해결할 때, A가 항상 S의 부분 수열이며 S의 각 위치에 1:1 대응된다는 점을 이용해 입력을 배열에서 정수로 바꾼것이 예시.)
// 5. 적용
