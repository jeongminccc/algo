//
//  12844_XOR.cpp
//  algo
//
//  Created by jm on 2020/09/05.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MAX = 500001;

int N,M;
int tree[4*MAX];
int lazy[4*MAX];
int original[MAX];

int init(int start, int end, int node){
    if(start == end) return tree[node] = original[start];
    
    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) ^ init(mid+1, end, node*2+1);
}

void query_lazy(int start, int end, int node){
    if(lazy[node] != 0){
        tree[node] ^= ((end-start+1) % 2)*lazy[node];
        if(start != end){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

int query(int start, int end, int node, int from, int to){
    query_lazy(start, end, node);
    if(end < from || start > to) return 0;
    if(from <= start && end <= to) return tree[node];
    
    int mid = (start + end)/2;
    return query(start, mid, node*2, from, to) ^ query(mid+1, end, node*2+1, from, to);
}

void query(int start, int end, int node, int from, int to, int dif){
    query_lazy(start, end, node);
    if(end < from || start > to) return;
    
    if(from <= start && end <= to){
        tree[node] ^= ((end-start+1) % 2)*dif;
        if(start != end){
            lazy[node*2] ^= dif;
            lazy[node*2+1] ^= dif;
        }
        return;
    }
    int mid = (start+end)/2;
    query(start, mid, node*2, from, to, dif);
    query(mid+1, end, node*2+1, from, to, dif);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; ++i) cin >> original[i];
        
    init(1,N,1);
    
    cin >> M;
    while(M--){
        int test, from, to;
        cin >> test >> from >> to;
        if(test == 2) cout << query(1, N, 1, from+1, to+1) << "\n";
        else{
            int k;
            cin >> k;
            query(1,N,1,from+1,to+1,k);
        }
    }
    return 0;
}


