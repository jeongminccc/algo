//
//  round, fixed, precision.cpp
//  algo
//
//  Created by jm on 2020/08/19.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a = 321.123456789;
    
    cout << a << endl; // 원래는 소수점 포함 6자리까지만 출력됨
    
    cout.precision(5); // 소수점 포함 5자리까지 출력 & 버리는 수는 자동으로 반올림됨
    cout << a << endl;
    
    cout << fixed; // 소수점 아래 숫자의 출력범위만 설정
    cout.precision(5);
    cout << a << endl;
    
    cout.unsetf(ios::fixed); // 적용되있던 fixed를 해제 -> 다시 소수점 포함 5자리까지만 출력
    cout << a << endl;
    
    cout << round(a) << endl; // 반올림 함수
    
    cout << ceil(a) << endl; // 무조건 올림함수
    
    cout << floor(a) << endl; // 무조건 내림 함수
    
    return 0;
}
