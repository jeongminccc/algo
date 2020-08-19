//
//  신촌_E.cpp
//
//
//  Created by jm on 2020/08/15.
//
#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
typedef long long ll;

string str;
ll num_list[MAX];
char char_list[MAX];
int left_posNum, right_posNum, left_posChar, right_posChar;

ll cal(ll a, ll b, char c){
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
    else return a / b;
}

void left(ll a){
    num_list[left_posNum+1] = a;
    left_posNum++;
    left_posChar++;
}

void right(ll a){
    num_list[right_posNum-1] = a;
    right_posNum--;
    right_posChar--;
}

int main(){
    cin >> str;
    bool minus_flag = false;
    string temp_num = "";
    int pos_num = 0, pos_char = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] != '/' && str[i] != '*' && str[i] != '+' && str[i] != '-'){ // 숫자 일시
            temp_num += str[i];
        }else{
            if(str[i] == '-' && i == 0){
                minus_flag = true;
                continue;
            }
            if(minus_flag) {num_list[pos_num] = -atoll(temp_num.c_str()); minus_flag = false;}
            else num_list[pos_num] = atoll(temp_num.c_str());
            char_list[pos_char] = str[i];
            temp_num = "";
            pos_char++;
            pos_num++;
        }
    }
    if(minus_flag) num_list[pos_num] = -atoll(temp_num.c_str());
    else num_list[pos_num] = atoll(temp_num.c_str());
    pos_num++;
    
    int temp_posChar = pos_char;
    left_posNum = 0; right_posNum = pos_num - 1; left_posChar = 0; right_posChar = pos_char - 1;
    while(temp_posChar--){
        ll compare_left = cal(num_list[left_posNum], num_list[left_posNum+1], char_list[left_posChar]);
        ll compare_right = cal(num_list[right_posNum-1], num_list[right_posNum], char_list[right_posChar]);
        
        if( ((char_list[left_posChar] == '*') || (char_list[left_posChar] == '/' )) && ((char_list[right_posChar] == '*') || (char_list[right_posChar] == '/' )) ){
                if(compare_left >= compare_right) left(compare_left);
                else right(compare_right);
        }
        else if( (char_list[left_posChar] == '*') || (char_list[left_posChar] == '/' )) left(compare_left);
        else if( (char_list[right_posChar] == '*') || (char_list[right_posChar] == '/' ) ) right(compare_right);
        else{
            if(compare_left >= compare_right) left(compare_left);
            else right(compare_right);
        }
    }
    
    cout << num_list[left_posNum] << endl;
    
    return 0;
}
