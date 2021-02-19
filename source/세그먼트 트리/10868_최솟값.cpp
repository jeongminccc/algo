//
//  10868_최솟값.cpp
//  algo
//
//  Created by jm on 2020/09/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 1e9 + 1;

int N,M;
int tree[400001];
int original[100001];

int init(int start, int end, int node){
    if(start == end) return tree[node] = original[start];
    
    int mid = (start+end)/2;
    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int find_min(int start, int end, int node, int from, int to){
    if(end < from || start > to) return INF;
    if(from <= start && end <= to) return tree[node];
    
    int mid = (start + end)/2;
    return min(find_min(start, mid, node*2, from, to), find_min(mid+1, end, node*2+1, from, to));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; ++i) cin >> original[i];
        
    init(1,N,1);
    
    while(M--){
        int from, to;
        cin >> from >> to;
        cout << find_min(1,N,1,from,to) << "\n";
    }
    return 0;
}


