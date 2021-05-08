#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calEachOp(vector<char> &op, vector<long long> &num, char option){
    long long ret = 0;
    
    for (int j=0; j<op.size(); ++j){
        if (op[j] == '+' && option == '+'){
            num[j] = num[j] + num[j+1];
            num.erase(num.begin() + (j+1));
            op.erase(op.begin() + j);
            j--;
        }
        else if (op[j] == '-' && option == '-'){
            num[j] = num[j] - num[j+1];
            num.erase(num.begin() + (j+1));
            op.erase(op.begin() + j);
            j--;
        }
        else if (op[j] == '*' && option == '*'){
            num[j] = num[j] * num[j+1];
            num.erase(num.begin() + (j+1));
            op.erase(op.begin() + j);
            j--;
        }
    }
    
    if (op.empty()) ret = num.front();
    return (ret);
}

long long calSum(vector<char> op, vector<long long> num, int order_option){
    long long ret = 0;
   
    if (order_option == 0 || order_option == 1){
        // cal +
        calEachOp(op, num, '+');
        if (order_option == 0){
            // cal - AND *
            calEachOp(op, num, '-');
            ret = calEachOp(op, num, '*');
        }
        else {
            // cal * AND -
            calEachOp(op, num, '*');
            ret = calEachOp(op, num, '-');
        }
    }
    else if (order_option == 2 || order_option == 3){
        // cal -
        calEachOp(op, num, '-');
        if (order_option == 2){
            // cal + AND *
            calEachOp(op, num, '+');
            ret = calEachOp(op, num, '*');
        }
        else {
            // cal * AND +
            calEachOp(op, num, '*');
            ret = calEachOp(op, num, '+');
        }
    }
    else {
        // cal *
        calEachOp(op, num, '*');
        if (order_option == 4){
            // cal + AND -
            calEachOp(op, num, '+');
            ret = calEachOp(op, num, '-');
        }
        else {
            // cal - AND +
            calEachOp(op, num, '-');
            ret = calEachOp(op, num, '+');
        }
    }
    return (ret);
}

long long solution(string expression) {
    long long answer = 0;

    vector<char> op;
    vector<long long> num;
    string tmp_num = "";

    for (char &c:expression){
        if (c == '*' || c == '+' || c == '-'){
            num.push_back(stoi(tmp_num));
            op.push_back(c);
            tmp_num = "";
        } else{
            tmp_num += c;
        }
    } num.push_back(stoi(tmp_num));

    for (int i=0; i<6; ++i) 
        answer = max(answer, abs(calSum(op, num, i)));

    return answer;
}