//
//  카카오 겨울 인턴십 2019 호텔 방 배정.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

map<ll, ll> m;

ll GetRoomNumber(ll num){
    if(m.find(num) == m.end()){ // 원하는 방이 비어있음
        m[num] = num + 1;
        return num;
    }else{ // 원하는 방이 차있음
        return m[num] = GetRoomNumber(m[num]); // 다음 빈방으로 이동
    }
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for(auto& a:room_number){
        answer.push_back(GetRoomNumber(a));
    }
    
    return answer;
}
