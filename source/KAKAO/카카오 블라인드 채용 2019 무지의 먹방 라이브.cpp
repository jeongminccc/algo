//
//  카카오 블라인드 채용 2019 무지의 먹방 라이브.cpp
//  algo
//
//  Created by jm on 2020/09/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

bool cmp(const pii&a, const pii&b){
    return a.second < b.second;
}

bool cmpForUpper(const pii&a, const pii&b){
    return a.first < b.first;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    priority_queue<pii, vector<pii>, greater<>> food_sorted;
    for(int i=0; i<food_times.size(); ++i)
        if(food_times[i] != 0) food_sorted.push({food_times[i], i+1}); // time과 index를 저장

    int sum_of_first = 0;
    while(1){
        if((food_sorted.top().first - sum_of_first) * food_sorted.size() >= k){ // 이번 순서에 먹방이 종료됨
            
            vector<pii> ans;
            while(!food_sorted.empty()){
                ans.push_back(food_sorted.top());
                food_sorted.pop();
            }
            sort(ans.begin(), ans.end(), cmp); // 남은 음식들을 index순서로 정렬
            unsigned long long index_ans = k % (unsigned long long)ans.size();
            answer = ans[index_ans].second;
            break;
        }
        
        int first = (food_sorted.top().first - sum_of_first);
        k -= first * food_sorted.size();
        sum_of_first += first;
        food_sorted.pop();
        
        if(food_sorted.size() == 0) {answer = -1; break;} // 남은 음식이 없음
    }
    return answer;
}
