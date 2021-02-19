//
//  7453_합이0인네정수.cpp
//  
//
//  Created by jm on 2020/08/16.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[4001], B[4001], C[4001], D[4001];
ll new_B[20000000];

int main(){
    int pos=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            new_B[pos++] = C[i] + D[j];
        }
    }
    sort(new_B, new_B + pos);
    
    ll cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            ll NewA = A[i] + B[j];
            ll NewB = lower_bound(new_B, new_B + pos, -NewA) - new_B;
            ll NewC = upper_bound(new_B, new_B + pos, -NewA) - new_B;
            
            if(NewA + new_B[NewB] == 0) {
                cnt += NewC - NewB;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
