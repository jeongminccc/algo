//
//  8_합친 LIS.cpp
//  algo
//
//  Created by jm on 2020/08/11.
//  Copyright © 2020 jm. All rights reserved.
//

// jlis(indexA, indexB) = A[indexA]와 B[indexB]에서 시작하는 합친 증가 부분 수열의 최대 길이

// DP
const long long NEGINF = numeric_limits<long long>::min();
typedef long long ll;
int n, m, A[100], B[100];
int cache[101][101];
int jlis(int indexA, int indexB){
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;
    ret = 2;
    ll a = (indexA == -1 ? NEGINF : A[indexA]);
    ll b = (indexB == -1 ? NEGINF : B[indexB]);
    ll maxElement = max(a,b);
    
    for(int nextA = indexA+1; nextA < n; ++nextA)
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1);
    for(int nextB = indexB+1; nextB < n; ++nextB)
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1);
    return ret;
}
