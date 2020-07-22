//
//  7_쿼드트리.cpp
//  algo
//
//  Created by jm on 2020/07/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

string quadTree(string::iterator& stn){
    char head = *stn;
    ++stn;
    
    if(head == 'b' || head == 'w'){
        return string(1, head);
    }
    string upperLeft = quadTree(stn);
    string upperRight = quadTree(stn);
    string lowerLeft = quadTree(stn);
    string lowerRight = quadTree(stn);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
    
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
//    int n;
    string quad;
    cin >> quad;
    
    string::iterator it = quad.begin();
    string ans = quadTree(it);
    
    cout << ans << endl;
    
    return 0;
}
