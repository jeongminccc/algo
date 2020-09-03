//
//  c++의 메모리구조.cpp
//  algo
//
//  Created by jm on 2020/09/02.
//  Copyright © 2020 jm. All rights reserved.
//

//          코드 영역          //
// 데이터 영역(전역 변수, static) //
//          힙 영역           //
//         스택 영역          //

#include <bits/stdc++.h>

using namespace std;

struct POINT{
    int m_STR, m_INT, m_PNT;
};

int N, ans=0;

void foo(struct POINT a){
    cout << "스택 영역에 할당된 foo에서 만들어진 구조체 : " << &a << endl;
    return;
}

int main(){
    static int q;
    cout << "데이터 영역에 할당된 전역 변수 : " << &N << endl;
    cout << "데이터 영역에 할당된 static 변수 : " << &q << endl;
    
    int *arr = new int[10];
    cout << "힙 영역에 할당된 배열 : " << arr << endl;
    delete[] arr;
    
    POINT a;
    cout << "스택 영역에 1번째로 할당된 구조체 : " << &a << endl;
    foo(a);
    
    POINT b;
    cout << "스택 영역에 2번째로 할당된 구조체 : " << &b << endl;
    int c=10;
    cout << "스택 영역에 3번째로 할당된 변수 : " << &c << endl;
    
    int &d = c;
    cout << "참조자로 선언한 변수 : " << &d << endl;
    // 메모리를 먹지 않는다.
    
    return 0;
}

