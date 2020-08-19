//
//  신촌_div2_A.cpp
//  algo
//
//  Created by jm on 2020/08/19.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <algorithm>

using namespace std;

double a[3], b[3], big=0, small=10e9;
bool compare(int a, int b){return a > b;}
int main(){
    cin >> a[0] >> a[1] >> a[2];
    big = a[0] >= a[1] ? (a[0] >= a[2] ? 0 : 2) : (a[1] >= a[2] ? 1 : 2);
    small = a[0] <= a[1] ? (a[0] <= a[2] ? 0 : 2) : (a[1] <= a[2] ? 1 : 2);

    sort(a, a+3, compare);
    double sum = (a[0]+a[1]-a[2]) / 2;
    
    if(a[0] - sum + a[1] - sum == a[2] && (a[0] - sum > 0) && (a[1] - sum > 0)) {
        cout << "1" << endl;
        cout << fixed;
        cout.precision(1);
        double ans1, ans2, ans3;
        
        ans1 = big == 0 ? (small == 1 ? a[0] - sum : sum) : (big == 1 ? (small == 0 ? a[0] - sum : sum) : a[1] - sum);
        ans2 = big == 0 ? (small == 2 ? a[0] - sum : sum) : (big == 2 ? (small == 0 ? a[0] - sum : sum) : a[1] - sum);
        ans3 = big == 1 ? (small == 2 ? a[0] - sum : sum) : (big == 2 ? (small == 1 ? a[0] - sum : sum) : a[1] - sum);
        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }
    else cout << "-1" << endl;

    return 0;
}
