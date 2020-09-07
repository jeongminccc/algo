//
//  9426_중앙값.cpp
//  algo
//
//  Created by jm on 2020/09/07.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
const int MAX = 250001;
const int MAX_ = 65536;

ll Answer;
int N, K, Q, pay[MAX];
ll tree[4*MAX];

ll update(int start, int end, int node, int index, ll val){
    if (end < index || index < start) return tree[node];
    if (start == end) return tree[node] += val;
    
    int mid = (start+end)/2;
    return tree[node] = update(start, mid, node * 2, index, val) + update(mid+1, end, node*2+1, index, val);
}

ll query(int start, int end, int node, ll val){
    if(start == end) return start;
    
    int mid = (start+end)/2;
    if (tree[node * 2] >= val) return query(start, mid, node*2, val);
    return query(mid+1, end, node*2+1, val-tree[node*2]);
}

int main()
{
    cin >> N >> K;
    Answer = 0;
    ll mid = (K+1)/2;
    
    for(int i=1; i<=N; ++i) {
        cin >> pay[i];
        update(0, MAX_, 1, pay[i], 1);
        if(i>=K){
            Answer += query(0, MAX_, 1, mid);
            update(0, MAX_, 1, pay[i-K+1], -1);
        }
    }
    cout << Answer;

    return 0;
}
