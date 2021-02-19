//
//  11025_요세푸스 문제 3.cpp
//  algo
//
//  Created by jm on 2020/09/18.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (ans + k) % i;
    }
    cout << ans + 1;
}
