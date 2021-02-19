//
//  참조 매개변수 사용법.cpp
//  algo
//
//  Created by jm on 2020/09/02.
//  Copyright © 2020 jm. All rights reserved.
//
//
#include <bits/stdc++.h>

using namespace std;

// 구조체명은 클래스명과 구분하기 위해 모두 대문자로 기입(클래스는 처음글자만 대문자)
struct STRUCT_A{
    int m_a; // 멤버변수들은 로컬변수들괴 구분을 위해 m을 붙여줌
};

struct STRUCT_B{
    int m_b;
}nameOfStruct_b; // 이렇게 바로 선언을 해줄 수도 있다.

struct{
    int m_c;
}nameOfStruct_c; // 이렇게 바로 선언을 해줄 수도 있다. 근데 매개변수로 전달하거나 할때 불가능함.


void foo_Value(struct STRUCT_A a){
    a.m_a = 2;
    return;
}

void foo_Reference(struct STRUCT_B& a){ // 참조로 구조체를 받음. (주소값을 받아 직접 접근이 가능)
                                        // 즉 참조자 a를 선언 하는것임. 값에의한 호출은 값만 복사해서 새로운 변수를 만드는건데
    a.m_b = 2; // 평소 구조체 쓰듯이 쓰면 됨.
    return;
}

void foo_Reference2(struct STRUCT_B* a){ // 구조체의 주소를 받아 포인터로 값을 변경.
    (*a).m_b = 3; // 포인터로 받았기에
    a->m_b = 3;   // 두가지 사용법이 존재
    return;
}

int main(){
    
    // 구조체 선언시 둘다 가능.
    STRUCT_A nameOfStruct_a;
    struct STRUCT_A nameOfStruct_a2;
    
    nameOfStruct_a.m_a = 1;
    nameOfStruct_b.m_b = 1;
    nameOfStruct_c.m_c = 1;
    
    cout << "값에의한 전달이 이루어 지기 전 : " << nameOfStruct_a.m_a << endl;
    foo_Value(nameOfStruct_a);
    cout << "값에의한 전달이 이루어 진 후 : " << nameOfStruct_a.m_a << endl;
    
    cout << "참조에의한 전달이 이루어 지기 전 : " << nameOfStruct_b.m_b << endl;
    foo_Reference(nameOfStruct_b);
    cout << "참조에의한 전달이 이루어 진 후 : " << nameOfStruct_b.m_b << endl;
    
    // 다른 형태의 참조전달
    cout << "참조에의한 전달이 이루어 지기 전 : " << nameOfStruct_b.m_b << endl;
    foo_Reference2(&nameOfStruct_b);
    cout << "참조에의한 전달이 이루어 진 후 : " << nameOfStruct_b.m_b << endl;
    
    return 0;
}
