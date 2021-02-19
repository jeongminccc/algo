//
//  8_외발뛰기.cpp
//  algo
//
//  Created by jm on 2020/07/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

// 먼저 재귀 호출 알고리즘을 사용하여 문제를 풀어보면
// return jump(y+jumpSize, x) || jump(y, x+jumpSize) 이런 형태가 될것이다.
// 그러나 이렇게 풀면, 최악의경우(모든칸이 1) 만들어지는 경로의 개수는 n에대해 지수적으로 늘어나게되고, n=100이므로 시간초과가된다.
// 여기서 주목해야 될 것은 만드는 경로의 수는 엄청나게 많지만 입력의 개수는 100x100 = 10,000개뿐이라는 사실.
// 즉, 비둘기집의 원리에 의해 중복으로 해결되는 부분 문제들이 항상 존재함을 알 수 있음.
// jump()는 참조적 투명 함수이므로, 메모이제이션을 적용하여 중복연산을 없앨 수 있다.

int n, board[100][100];
int cache[100][100];
int jump2(int y, int x){
    
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    
//    return jump2(y + board[y][x], x) + jump2(y, x + board[y][x]);
    int jumpSize = board[y][x];
    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            cin >> board[i][j];
        }
    }
    
    int ans = jump2(0, 0);
    if(ans > 0) cout << "C" << endl;
    
    return 0;
}
