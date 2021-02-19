//
//  1395_스위치.cpp
//  algo
//
//  Created by jm on 2020/09/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N,M;
ll tree[400001];
ll lazy[400001] = {0};
ll original[100001];

ll init_switch(int start, int end, int node){
    if(start == end) return tree[node] = 0;
    
    int mid = (start+end)/2;
    return tree[node] = init_switch(start, mid, node*2) + init_switch(mid+1, end, node*2+1);
}

void update_lazy(int start, int end, int node){
    if(lazy[node] != 0){
        if(lazy[node] % 2 == 1) tree[node] = (end-start+1) - tree[node]; // 홀수번 껐다 켰다 하므로 반대
        // else 스위치를 짝수번 껐다 켰다하므로 그대로임.
            
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right){
    update_lazy(start, end, node);
    if(start > right || end < left) return;
    
    if(left <= start && end <= right){
        tree[node] = (end - start + 1) - tree[node]; // 모두 겹치는 구간을 가진 노드를 만나면 이번 노드에만 변경값을 저장해두고
        if(start != end){
            lazy[node*2] += 1;         // 자식 노드들에게는 lazy값만 전달 후 더이상 진행하지 않고 종료
            lazy[node*2+1] += 1;
        }
        return;
    }
    
    int mid = (start+end)/2;
    update_range(start, mid, node*2, left, right);
    update_range(mid+1, end, node*2+1, left, right);
    tree[node] = tree[node*2] + tree[node*2+1]; // 구간에 걸쳐 있는 것들도 update 해줌
}

ll sum(int start, int end, int node, int left, int right){
    update_lazy(start, end, node);
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    
    init_switch(1,N,1); // 각 구간마다 스위치가 몇개나 켜져 있는지 초기화
    
    while(M){
        int test, from, to;
        cin >> test;
        if(test == 0){
            cin >> from >> to;
            update_range(1, N, 1, from, to);
        }else{
            cin >> from >> to;
            cout << sum(1, N, 1, from, to) << "\n";
        }
        M--;
    }
    return 0;
}


