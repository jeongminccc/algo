//
//  세그먼트 트리.cpp
//  algo
//
//  Created by jm on 2020/08/13.
//  Copyright © 2020 jm. All rights reserved.
// 출처 https://blog.naver.com/ndb796/221282210534

// 특정 구간의 합을 구할때, O(N)보다 빠르게 구할 수 있다.

// 트리구조를 만들자.
// 최상단 노드에는 전체 구간의 합이, 두번째 노드에는 [0,n/2] 구간의 합이, 세번째 노드에는 [n/2+1, n] 구간의 합이 입력된다.
// 구간 합 트리에 대해서는 인덱스의 번호가 1부터 시작한다. X2했을때 왼쪽 자식 노드를 가리키므로 효율적.

// 반복적으로 구현하는 것 보다 재귀적으로 구현하는게 더 간단하다.

int init(int start, int end, int node){
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    // 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 한다.
    return tree[node] = init(start, mid, node * 2) + init(mid+1, end, node*2 + 1);
}

// 구간 합 트리의 원소개수는, N보다 큰 제곱수중 가장 작은 제곱수의 2배만큼 필요하다. -> 보통 N * 4 해주면 됨

// 구간 합을 구하는 함수 만들기
// 트리구조이기 때문에, 데이터 탐색 비용은 O(logN)이다.
// 따라서 구간 합을 항상 O(logN)에 구할 수 있다.
// 재귀로 구현.

// start - 시작인덱스, end - 끝 인덱스
// left, right - 구간 합 구하고자 하는 범위
int sum(int start, int end, int node, int left, int right){
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;
    // 범위 안에 있는 경우
    if(left <= start && end <= right) return tree[node];
    // 그렇지 않다면 두부분으로 나누어 합을 구하기
    int mid = (start+end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

// 특정원소의 값을 수정하는 함수 만들기
// 특정원소의 값을 수정하려 할때에는, 해당 원소를 포함하고있는 모든 구간 합 노드들을 갱신해주면 된다.

void update(int start, int end, int node, int index, int dif){
    
    if(index < start || index > end) return;
    
    tree[node] += dif;
    if(start == end) return;
    int mid = (start+end) / 2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index,dif);
}
