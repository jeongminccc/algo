//
//  브랜디_A.cpp
//  algo
//
//  Created by jm on 2020/08/29.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
using namespace std;

int step[6] = {0}, age;
double max_beat;

int main() {
    cin >> age;
    max_beat = double(220 - age);
    
    double beat, percentage;
    while(cin >> beat){
//        cin >> beat;           이거 그대로 출력해도 틀렸고
//        if(cin.eof()) break;   순서 바꿔서 출력해도 틀렸었음
        
        percentage = beat / max_beat;
 
        if(percentage < double(0.60000)) step[0]++;
        else if(percentage < double(0.68000)) step[1]++;
        else if(percentage < double(0.75000)) step[2]++;
        else if(percentage < double(0.80000)) step[3]++;
        else if(percentage < double(0.90000)) step[4]++;
        else step[5]++;
    }
    
    for(int i=5; i>=0; --i) cout << step[i] << " ";
    
    return 0;
}
