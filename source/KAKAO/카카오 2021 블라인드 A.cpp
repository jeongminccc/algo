//
//  카카오 2021 블라인드 A.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string DeleteSpecial(string s){ //알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)
    string ret = "";
    for(auto& a:s){
        if( ('a' <= a && a <= 'z') || ('0' <= a && a <= '9') || a == '-' || a == '_' || a == '.') ret += a;
    }
    return ret;
}

string DeleteDots(string s){
    string ret = "";
    bool dot_flag = false;
    for(auto& a:s){
        if( a == '.' ){
            dot_flag = true;
        }
        else if( ('a' <= a && a <= 'z') || ('0' <= a && a <= '9') || a == '-' || a == '_' || a == '.'){
            if(dot_flag) { ret += '.'; dot_flag = false; }
            ret += a;
        }
    }
    return ret;
}

string DeleteEndOfDots(string s){
    if(s[0] == '.') s.erase(0,1);
    if(s[s.size()-1] == '.') s.erase(s.size()-1, 1);
    return s;
}
string solution(string new_id) {
    
    // 1단계
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);

    // 2단계
    new_id = DeleteSpecial(new_id);

    // 3
    new_id = DeleteDots(new_id);

    // 4
    new_id = DeleteEndOfDots(new_id);

    // 5
    if(new_id == "") new_id = "a";

    // 6
    if(new_id.size() > 15) new_id.erase(15 , new_id.size());
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);

    // 7
    while(new_id.size() < 3)
        new_id += new_id[new_id.size()-1];
    
    return new_id;
}

int main(){
    solution("z-+.^.");
    return 0;
}
