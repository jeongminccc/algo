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
    } num_list[pos_num] = atoll(temp_num.c_str()); pos_num++;
    
    int temp_posChar = pos_char;
    int left_posNum=0, right_posNum = pos_num - 1, left_posChar = 0, right_posChar = pos_char - 1;
    while(temp_posChar--){
        ll compare_left=0, compare_right=0;
        
        if( ((char_list[left_posChar] == '*') || (char_list[left_posChar] == '/' )) && ((char_list[right_posChar] == '*') || (char_list[right_posChar] == '/' )) )
        { // 양쪽다 곱셈 혹은 나눗셈
            if(char_list[left_posChar] == '*'){ // 왼쪽이 곱셈인경우
                compare_left = num_list[left_posNum] * num_list[left_posNum+1];
                if(char_list[right_posChar] == '/'){ // 왼쪽이 곱셈 오른쪽이 나눗셈
                    compare_right = num_list[right_posNum-1] / num_list[right_posNum];
                }else{ // 왼쪽 곱셈 오른쪽 곱셈
                    compare_right = num_list[right_posNum] * num_list[right_posNum-1];
                }

                if(compare_left >= compare_right){ // 왼쪽 연산부터
                    num_list[left_posNum+1] = compare_left;
                    left_posNum++;
                    left_posChar++;
                }else{
                    num_list[right_posNum-1] = compare_right;
                    right_posNum--;
                    right_posChar--;
                }
            }else{
                compare_left = num_list[left_posNum] / num_list[left_posNum+1];
                if(char_list[right_posChar] == '/'){ // 왼쪽이 나눗셈 오른쪽이 나눗셈
                    compare_right = num_list[right_posNum-1] / num_list[right_posNum];
                }else{ // 왼쪽 곱셈 오른쪽 곱셈
                    compare_right = num_list[right_posNum] * num_list[right_posNum-1];
                }

                if(compare_left >= compare_right){ // 왼쪽 연산부터
                    num_list[left_posNum+1] = compare_left;
                    left_posNum++;
                    left_posChar++;
                }else{
                    num_list[right_posNum-1] = compare_right;
                    right_posNum--;
                    right_posChar--;
                }
            }
        }
        
        else if( (char_list[left_posChar] == '*') || (char_list[left_posChar] == '/' )){ //왼쪽이 곱셈나눗셈 오른쪽은 더하기빼기
            if(char_list[left_posChar] == '*'){ // 왼쪽이 곱셈인경우
                compare_left = num_list[left_posNum] * num_list[left_posNum+1];
            }else{
                compare_left = num_list[left_posNum] / num_list[left_posNum+1];
            }
            
            num_list[left_posNum+1] = compare_left;
            left_posNum++;
            left_posChar++;
        }
        
        else if( (char_list[right_posChar] == '*') || (char_list[right_posChar] == '/' ) ){ // 오른쪽이 곱셈 나눗셈 왼쪽은 더하기 빼기
            if(char_list[right_posChar] == '*'){ // 오른쪽이 곱셈인경우
                compare_right = num_list[right_posNum-1] * num_list[right_posNum];
            }else{
                compare_right = num_list[right_posNum-1] / num_list[right_posNum];
            }
            
            num_list[right_posNum-1] = compare_right;
            right_posNum--;
            right_posChar--;
        }
        
        else{ // 왼쪽 오른쪽 둘다 더하기 빼기
            if(char_list[left_posChar] == '+'){ // 왼쪽이 더하기인경우
                compare_left = num_list[left_posNum] + num_list[left_posNum+1];
                if(char_list[right_posChar] == '-'){ // 왼쪽이 더하기 오른쪽이 빼기
                    compare_right = num_list[right_posNum-1] - num_list[right_posNum];
                }else{ //
                    compare_right = num_list[right_posNum] + num_list[right_posNum-1];
                }

                if(compare_left >= compare_right){ // 왼쪽 연산부터
                    num_list[left_posNum+1] = compare_left;
                    left_posNum++;
                    left_posChar++;
                }else{
                    num_list[right_posNum-1] = compare_right;
                    right_posNum--;
                    right_posChar--;
                }
            }else{ // 왼쪽이 빼기
                compare_left = num_list[left_posNum] - num_list[left_posNum+1];
                if(char_list[right_posChar] == '-'){
                    compare_right = num_list[right_posNum-1] - num_list[right_posNum];
                }else{
                    compare_right = num_list[right_posNum] + num_list[right_posNum-1];
                }
                
                if(compare_left >= compare_right){ // 왼쪽 연산부터
                    num_list[left_posNum+1] = compare_left;
                    left_posNum++;
                    left_posChar++;
                }else{
                    num_list[right_posNum-1] = compare_right;
                    right_posNum--;
                    right_posChar--;
                }
            }
        }
    }
    cout << num_list[left_posNum] << endl;
    
    return 0;
}
