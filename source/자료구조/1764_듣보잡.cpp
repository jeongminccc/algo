//
//  1764_듣보잡.cpp
//  algo
//
//  Created by jm on 2020/10/04.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    set<string> s;
    
    for(int i=0; i<N; ++i){
        string ipt;
        cin >> ipt;
        s.insert(ipt);
    }
    
    vector<string> ans;
    while(M--){
        string ipt;
        cin >> ipt;
        if(s.find(ipt) != s.end()) ans.push_back(ipt);
        // find 는 O(logN)이므로 충분
        // 다른 방법으로 binary_search(v.begin(), v.end(), ipt)도 있음
        // lower_bound, upper_bound로 찾는 방법은 두개의 결과값이 같으면 찾는 원소가 없다는 말.
        // set은 삽입이 logN, 삭제가 1
    }
    
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(string& a:ans) cout << a << '\n';
}

