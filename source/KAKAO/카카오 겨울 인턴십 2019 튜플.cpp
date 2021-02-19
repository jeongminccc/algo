//
//  카카오 겨울 인턴십 2019 튜플.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    bool start_flag=false;
    string temp = "";
    vector<vector<int>> v;
    vector<int> temp_v;
    
    for(auto& a:s){
        if(a == '{'){ start_flag = true; continue;}
        if(a == ',' && start_flag){
            temp_v.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        
        if(a == '}'){
            if(start_flag){
                temp_v.push_back(stoi(temp));
                v.push_back(temp_v);
            }
            
            temp_v.clear();
            temp.clear();
            start_flag = false;
            continue;
        }
        if(a >= '0' && a <= '9')
            temp += a;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> answer;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            bool flag = false;
            for(int k=0; k<answer.size(); k++){
                if(answer[k] == v[i][j]) flag = true;
            }
            if(!flag) answer.push_back(v[i][j]);
        }
    }
    return answer;
}

int main(){
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    return 0;
}
