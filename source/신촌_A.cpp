//
//  신촌_A.cpp
//  
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<int,int> arr[100001];
int n, pos=0;
ll sum[100001] = {0};

int main(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if(i == 0) continue;
        sum[i] = sum[i-1] + arr[i-1].second; // 이때까지 모은 상금의 합
    }
    
    bool flag = false;
    for(int i=0; i<n; i++){
        if(!flag && (sum[i] > arr[i].first)){ // 한번 부족한 일이 생겼을때
            pos = i-1;
            flag = true;
        }
        if(flag){ // 2번째 부족해질때
            if((sum[i] - arr[pos].second) > arr[i].first){
                cout << "Zzz" << endl;
                return 0;
            }
        }
    }
    cout << "Kkeo-eok" << endl;
    return 0;
}
