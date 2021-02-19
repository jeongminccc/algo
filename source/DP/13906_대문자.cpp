//
//  13906_대문자.cpp
//  algo
//
//  Created by jm on 2020/09/03.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

string lower;
int cache[1001]; // i부터 끝까지 만들 수 있는 대문자 개수
int alphabet[26];

int main(){
    cin >> lower;

    for(int i=(int)lower.length(); i>=0; --i){
        memset(alphabet, 0, sizeof(alphabet));
        cache[i] = 1;
        
        for(int j=i; j<(int)lower.length(); ++j){
            
            alphabet[lower[j] - 'a']++;
            if(alphabet[lower[j] - 'a'] == 3){
                cache[i] += cache[j+1];
                cache[i] %= MOD;
            }
        }
    }
    cout << cache[0] - 1;
    return 0;
}
