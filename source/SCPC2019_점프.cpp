//
//  SCPC2019_점프.cpp
//  algo
//
//  Created by jm on 2020/08/21.
//  Copyright © 2020 jm. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MAX = 1e6;
int Answer;
vector<ll> num_list;

void init(){
    ll sum=0;
    for(int i=1; i<MAX; i++){
        sum += i;
        num_list.push_back(sum);
    }
}

int main(int argc, char** argv)
{
    int T, test_case;
    init();
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    ll from, to;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cin >> from >> to;
        Answer = 0;
        
        auto min_num = upper_bound(num_list.begin(), num_list.end(), from) - num_list.begin();
        auto max_num = upper_bound(num_list.begin(), num_list.end(), to) - num_list.begin();
        
        if(min_num == max_num){
            for(ll i = from; i <= to; i++){
                ll temp = i;
                int temp_ans = 0;
                long tempMaxNum = max_num;
                while(temp>0){
                    temp -= num_list[tempMaxNum - 1];
                    temp_ans += tempMaxNum;
                    tempMaxNum = upper_bound(num_list.begin(), num_list.end(), temp) - num_list.begin();
                } Answer = max(Answer, temp_ans);
            }
        }
        
        else{
            min_num = max_num - 1;
            from = max(num_list[min_num] - max_num, from);
            for(ll i = from; i < num_list[min_num]; i++){
                ll temp = i;
                int temp_ans = 0;
                long tempMinNum = min_num;
                while(temp>0){
                    temp -= num_list[tempMinNum - 1];
                    temp_ans += tempMinNum;
                    tempMinNum = upper_bound(num_list.begin(), num_list.end(), temp) - num_list.begin();
                } Answer = max(Answer, temp_ans);
            }

            for(ll i = num_list[min_num]; i <= to; i++){
                ll temp = i;
                int temp_ans = 0;
                long tempMaxNum = max_num;
                while(temp>0){
                    temp -= num_list[tempMaxNum - 1];
                    temp_ans += tempMaxNum;
                    tempMaxNum = upper_bound(num_list.begin(), num_list.end(), temp) - num_list.begin();
                } Answer = max(Answer, temp_ans);
            }
        }
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
