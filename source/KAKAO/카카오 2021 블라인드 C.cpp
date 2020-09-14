//
//  카카오 2021 블라인드 C.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> pq[24];
    multiset<int> ms[24];
    
    for(int i=0; i<info.size(); ++i){
        int pq_index = 0, pos=0;
        string temp = "";
        for(auto& a:info[i]){
            if(a == ' '){
                if(pos == 0){
                    if(temp == "python") pq_index |= (1 << 4);
                    else if(temp == "java") pq_index |= (1 << 3);
                }
                else if(pos == 1 && temp == "frontend") pq_index |= (1 << 2);
                else if(pos == 2 && temp == "senior") pq_index |= (1 << 1);
                else if(pos == 3 && temp == "pizza") pq_index |= 1;

                pos++;
                temp = "";
            }
            else temp += a;
        }
        ms[pq_index].insert(stoi(temp));
    }
    
    for(int i=0; i<query.size(); ++i){
        bool pq_index_set[24] = {false}, flag_first = false, flag_second = false, flag_third = false, flag_four = false;
        int pos=0, pq_index = 0;
        string temp = "";
        for(auto& a:query[i]){
            if(a == ' '){
                if(temp == "and"){ temp = ""; continue;}
                
                if(pos == 0){
                    if(temp == "-") flag_first = true;
                    else if(temp == "python") pq_index |= (1 << 4);
                    else if(temp == "java") pq_index |= (1 << 3);
                }
                else if(pos == 1){
                    if(temp == "-") flag_second = true;
                    else if(temp == "frontend") pq_index |= (1 << 2);
                }
                else if(pos == 2){
                    if(temp == "-") flag_third = true;
                    else if(temp == "senior") pq_index |= (1 << 1);
                }
                else if(pos == 3){
                    if(temp == "-") flag_four = true;
                    else if(temp == "pizza") pq_index |= 1;
                }

                pos++;
                temp = "";
            }
            else temp += a;
        }
        int limit_score = stoi(temp);
        
        int ret = 0;
        for(int j=0; j<24; ++j){
            if(flag_first){ // 모든 경우 가능시
                if(flag_second){
                    if(flag_third){
                        if(flag_four){
                            auto iter = lower_bound(ms[j].begin(), ms[j].end(), limit_score);
                            
                        }else if (j & 1){ // pizza
                            
                        }else{ // chicken
                            
                        }
                    }else if(j & (1 << 1)){ // senior
                        if(flag_four){
                            
                        }else if (j & 1){ // pizza
                            
                        }else{ // chicken
                            
                        }

                    }else{ // junior
                        if(flag_four){
                            
                        }else if (j & 1){ // pizza
                            
                        }else{ // chicken
                            
                        }
                    }
                }else if(j & (1 << 2)){ // front
                    
                }else{ // back
                    
                }
            }
        }
    }
    
    
    return answer;
}

//     cpp, java, python 중 하나입니다. 2bit
//직군은 backend, frontend 중 하나입니다. 1bit
//경력은 junior, senior 중 하나입니다. 1bit
//소울푸드는 chicken, pizza 중 하나 1bit

// 00000 cpp / back / junior / chicken
// 01000 java / back / junior / chicken
// 10000 python / back / junior / chicken
