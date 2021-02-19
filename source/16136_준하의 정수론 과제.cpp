//
//  16136_준하의 정수론 과제.cpp
//  algo
//
//  Created by jm on 2020/08/14.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int N,Q,arr[100001],prime_arr[1000001], M,K;
bool primeArr[1000001] = {false}, diviArr[100001];
vector<int> primeNum;
ll segTree[400001];

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

void eratos(){
    for(int i=2; i<1000000; i++){
        if(!primeArr[i]){
            primeNum.push_back(i);
            for(int j=i*2; j<1000000; j+=i){
                primeArr[j] = true;
            }
        }
    }
}

int divisor(int a){
    int ret = 1;
    
    for(int i=0; i<primeNum.size(); i++){
        if(primeNum[i] > a) break;
        
        int divisor_num_temp = 1;
        while(a % primeNum[i] == 0){
            a /= primeNum[i];
            divisor_num_temp++;
        }
        ret *= divisor_num_temp;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> Q;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int test, from, to;
    eratos();
    segment_init(0, N - 1, 1);
    for(int i = 1; i < 1000001; i++){
      for(int j = i; j <= 1000000; j += i)
        prime_arr[j]++;
    }
    
    while(Q--){
        long long ans=0;
        cin >> test >> from >> to;
        if(test == 1){
            // 소인수 분해해서 약수 개수 찾기
            for(int i=from; i<=to; i++){
                if(arr[i-1] <= 2) continue;
                
                int temp = -arr[i-1];
//                arr[i-1] = divisor(arr[i-1]);
                arr[i-1] = prime_arr[arr[i-1]];
                temp += arr[i-1];
                segment_update(0, N - 1, 1, i-1, temp);
            }
        }else{
            ans = segment_sum(0, N - 1, 1, from-1, to-1);
            cout << ans << "\n";
        }
    }
    return 0;
}

