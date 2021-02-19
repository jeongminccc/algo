//
//  10999_구간합 구하기2.cpp
//  algo
//
//  Created by jm on 2020/09/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N,M,K;
ll tree[4000001];
ll lazy[4000001] = {0};
ll original[1000001];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = original[start];
    
    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void update_lazy(int start, int end, int node){
    if(lazy[node] != 0){
        tree[node] += (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right, ll dif){
    update_lazy(start, end, node);
    if(start > right || end < left) return;
    
    if(left <= start && end <= right){
        tree[node] += (end-start+1)*dif; // 모두 겹치는 구간을 가진 노드를 만나면 이번 노드에만 변경값을 저장해두고
        if(start != end){
            lazy[node*2] += dif;         // 자식 노드들에게는 lazy값만 전달 후 더이상 진행하지 않고 종료
            lazy[node*2+1] += dif;
        }
        return;
    }
    
    int mid = (start+end)/2;
    update_range(start, mid, node*2, left, right, dif);
    update_range(mid+1, end, node*2+1, left, right, dif);
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
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) {
        cin >> original[i];
    }
    
    init(1,N,1);
    
    while(M>0 || K>0){
        int test, from, to;
        cin >> test;
        if(test == 1){
            ll new_num;
            cin >> from >> to >> new_num;
            update_range(1, N, 1, from, to, new_num);
            M--;
        }else{
            cin >> from >> to;
            cout << sum(1, N, 1, from, to) << "\n";
            K--;
        }
    }
    return 0;
}


