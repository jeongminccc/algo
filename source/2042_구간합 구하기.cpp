//
//  2042_구간합 구하기.cpp
//  algo
//
//  Created by jm on 2020/08/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N,arr[1000001], M,K;
vector<int> primeNum;
ll segTree[4000001];

ll segment_init(int start, int end, int node){
    if(start == end) return segTree[node] = arr[start];
    int mid = (start+end)/2;
    return segTree[node] = segment_init(start, mid, node*2) + segment_init(mid+1, end, node*2+1);
}

ll segment_sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return segTree[node];
    int mid = (start+end) / 2;
    return segment_sum(start, mid, node*2, left, right) + segment_sum(mid+1, end, node*2+1, left, right);
}

void segment_update(int start, int end, int node, int index, int dif){
    if(start > index || end < index) return;
    
    segTree[node] += dif;
    if(start == end) return;
    int mid = (start+end) / 2;
    segment_update(start, mid, node*2, index, dif);
    segment_update(mid+1, end, node*2+1, index, dif);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int test, index, new_num;
    segment_init(0, N - 1, 1);
    
    while(M>0 || K>0){
        ll ans=0;
        cin >> test >> index >> new_num;
        if(test == 1){
            int temp = -(arr[index-1] - new_num);
            arr[index-1] = new_num;
            segment_update(0, N - 1, 1, index-1, temp);
            M--;
        }else{
            ans = segment_sum(0, N - 1, 1, index-1, new_num-1);
            cout << ans << "\n";
            K--;
        }
    }
    return 0;
}

