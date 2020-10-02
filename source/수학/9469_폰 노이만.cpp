//
//  9469_폰 노이만.cpp
//  algo
//
//  Created by jm on 2020/10/02.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
              
int main(){
    int t;
    cin >> t;
    while(t--){
        int caseNum;
        cin >> caseNum;
        cout << caseNum << " ";

        double distance, speed_a, speed_b, speed_fly;
        cin >> distance >> speed_a >> speed_b >> speed_fly;
        
        double time = distance / (speed_a + speed_b);
        cout << time * speed_fly << '\n';
    }
}
