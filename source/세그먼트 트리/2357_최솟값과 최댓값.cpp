//
//  2357_최솟값과 최대값.cpp
//  algo
//
//  Created by jm on 2020/08/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
#define INF 0xffffffff;
using namespace std;

int N,arr[100001], M,K;
ll segTree[400001][2];

ll segment_init_min(int start, int end, int node){
    if(start == end)
        return segTree[node][0] = arr[start];
    int mid = (start+end)/2;
    return segTree[node][0] = min(segment_init_min(start, mid, node*2),segment_init_min(mid+1, end, node*2+1) );
}

ll segment_init_max(int start, int end, int node){
    if(start == end)
        return segTree[node][1] = arr[start];
    int mid = (start+end)/2;
    return segTree[node][1] = max(segment_init_max(start, mid, node*2), segment_init_max(mid+1, end, node*2+1));
}

ll find_min(int start, int end, int node, int left, int right){
    if(left > end || right < start) return INF;
    if(start >= left && end <= right) return segTree[node][0];
    
    int mid = (start + end)/2;
    return min(find_min(start, mid, node*2, left, right) , find_min(mid+1, end, node*2+1, left, right));
}

ll find_max(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(start >= left && end <= right) return segTree[node][1];
    
    int mid = (start + end)/2;
    return max(find_max(start, mid, node*2, left, right) , find_max(mid+1, end, node*2+1, left, right));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    segment_init_min(0, N - 1, 1);
    segment_init_max(0, N - 1, 1);
    
    while(M--){
        int from, to;
        cin >> from >> to;
        from--; to--; // index로 활용하기 위해
        
        cout << find_min(0, N - 1, 1, from, to) << " " << find_max(0, N - 1, 1, from, to) << "\n";
    }
    
    return 0;
}

