//
//  카카오 2021 블라인드 B.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& a:orders) sort(a.begin(), a.end());
    
    for(int i=0; i<course.size(); ++i){
        map<string,int> m; // 중복 검사를 위한 map
        int cnt_max = 0;
        
        for(int j=0; j<orders.size(); ++j){
            vector<int> combi; // 조합을 만들기 위한 벡터
            
            if(orders[j].size() < course[i]) continue;
            for(int k=0; k<orders[j].size() - course[i]; ++k) combi.push_back(0);
            for(int k=0; k<course[i]; ++k) combi.push_back(1);
            
            do{
                string input = "";
                for(int k=0; k<combi.size(); k++)
                    if(combi[k] == 1)
                        input += orders[j][k];
                
                m[input]++;
                cnt_max = max(cnt_max, m[input]);
            }while(next_permutation(combi.begin(), combi.end()));
        }
        
        for(auto& a:m) if(a.second == cnt_max && cnt_max >= 2) answer.push_back(a.first);
    }

    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    sort(answer.begin(), answer.end());
    for(auto& a:answer) cout << a << endl;
    
    return answer;
}

int main(){
    vector<string> s = {"XYZ", "XWY", "WXA"};
    vector<int> i = {2,3,4};
    solution(s, i);
    
    return 0;
}
//    ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]
