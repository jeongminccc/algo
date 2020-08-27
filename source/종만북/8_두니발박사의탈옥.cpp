//
//  8_두니발박사의탈옥.cpp
//  algo
//
//  Created by jm on 2020/08/27.
//  Copyright © 2020 jm. All rights reserved.
//

// d일 후에 두니발 박사가 각 마을에 있을 확률을 계산해라.
// 예제 입력을 손으로 풀어보면서 감을 잡아본다.
// 각 시나리오의 확률을 직접 계산해보면서 모든 확률을 계산해서 더하면 되겠다는 발상을 얻을 수 있다.

// 완전 탐색에서 시작
// 마을 p에서 마을 q까지 가는 길이 n+1인 경로들을 모두 생성하는 작업은 완전 탐색의 전매특허이다.
// p에서 시작해 n번 인접한 마을로 옮기는 모든 경로를 생성하고, 이 중 q에서 끝나는 것들이 출현할 확률을 계산해 그들의 합을 반환한다.

int n, d, p, q;
// connected - 마을 i, j가 연결되어있는지
// deg - 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
double search(vector<int>& path){
    // 기저사례 : d일이 지난경우
    if(path.size() == d+1){
        // 이 시나리오가 q에서 끝나지 않는다면 무효
        if(path.back() != q) return 0.0;
        double ret = 1.0;
        for(int i=0; i+1<path.size(); ++i)
            ret /= deg[path[i]];
        return ret;
    }
    double ret = 0;
    // 경로의 다음 위치를 결정한다.
    for(int there=0; there<n; ++there)
        if(connected[path.back()][there]){
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    return ret;
}

// 이대로는 메모이제이션을 할 수 없다.
// 이전에 배운대로, 이전에 선택한 조각들에 대한 정보를 가능한 한 최소한도로 줄일 필요가 있다.
// search()에 전달되는 path변수가 쓰이는 용도는 크게 세가지이다.
// 1. path의 마지막 원소는 현재 위치 : 다음 마을을 결정할 때 필요
// 2. path의 길이는 탈옥 후 지난 날짜 : 경로가 끝났는지 알 때 필요
// 3. 확률 계산 : 완성된 경로의 출현 확률을 계산할 때 필요

// -> 1. path대신 현재위치 here와 탈옥 후 지난 날짜 days를 재귀 호출에 전달한다.
// -> 2. 전체 경로의 확률을 계산하는 것이 아니라, 현재 위치에서 시작해서 남은 날짜 동안 움직여 q에 도달할 확률을 계산한다.

// search2(here, days) = 두니발 박사가 days일째에 here번 마을에 숨어있을떄, 마지막 날에 q번 마을에 있을 조건부 확률을 반환.

// 조건부 확률?
// 동적 계획법 레시피에서, 재귀 함수는 앞으로 선택하는 조각들의 결과만을 반환해야 한다고 이야기 했다.
// 최대 점수를 구할 때는 앞으로 하는 선택들의 점수의 합만을 반환했고, 경우의 수를 셀 때는 앞으로 하는 선택들의 경우의 수만을 반환했다.
// 확률을 구할 때도, 비슷한 방향으로 구하면 된다.

// DP 알고리즘 O(nd)개의 부분문제를 갖고 각각을 O(n)에 해결하므로 O(n^2d)

int n, d, p, q;
double cache[51][101];
int connected[51][51], deg[51];
double search2(int here, int days){
    if(days == d) return (here == q ? 1.0 : 0.0);
    
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there){
        if(connected[here][there])
            ret += search2(there, days+1) / deg[here];
    }
    return ret;
}

// 반대 방향에서 풀기
// 시간복잡도 O(n^2d) 는 질문으로 주어지는 도시 하나당 걸리는 시간이므로, 테스트 케이스 하나당 O(n^2dt)가 된다.
// 부분 문제 정의만 바꾸면 더 빠르게 구현할 수 있다.
// 계산의 순서를 반대 방향으로 바꾸는 것인데, 접근을 바꿔서 경로의 반대쪽 끝(q)부터 경로를 만들어 나가면 문제가 훨씬 쉬워진다.
// search3(here, days) = 탈옥 후 days일째에 두니발 박사가 here번 마을에 숨어 있을 확률

// 이를 통해 q가 바뀔때 마다 모든 값을 재계산할 필요가 없고, 따라서 한 테케당 시간 복잡도를 O(n^2d)로 줄일 수 있다.
int n, d, p, q;
double cache[51][101];
int connected[51][51], deg[51];
double search3(int here, int days){
    if(days == 0) return (here == p ? 1.0 : 0.0);
    
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there)
        if(connected[here][there])
            ret += search3(there, days-1) / deg[there];
    return ret;
}

// 마르코프 연쇄(Markov Chain)
// 다음과 같은 성질들때문에, 이 문제에서 다루는 마을들은 마르코프 연쇄라고 부르는 모델로 표현할 수 있다.

// - 유한개의 상태가 있다
// - 매 시간마다 상태가 변경된다.
// - 어떤 상태 a에서 다른 상태 b로 옮겨갈 확률은 현재 상태 a에만 좌우된다. a이전에 어느 상태에 있었는지, 현재 시간은 얼마인지 등은 영향을 주지 않는다.

// 마르코프 연쇄는 현실 세계의 많은 현상들을 모델링 하기 위해 종종 사용되는 유용한 모델이다.
