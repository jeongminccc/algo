#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool cmpVpii(vector<pair<int,int>> &a, vector<pair<int,int>> &b){
    return (a[0].first >= b[0].first);
}

bool cmpPii(pair<int,int> &a, pair<int,int> &b){
    if (a.first != b.first) return (a.first > b.first);
    return (a.second < b.second);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<pair<int,int>> sorted_plays[100]; // 첫번째 pair는 총 play
    map<string, int> m; // 각 장르에 index를 부여하기 위함
    
    int idx = 0;
    for (int i=0; i<genres.size(); ++i){
        if (m.find(genres[i]) == m.end()){
            m[genres[i]] = idx++;
            sorted_plays[m[genres[i]]].push_back({plays[i], 0});
        }
        else
            sorted_plays[m[genres[i]]][0].first += plays[i];
        
        sorted_plays[m[genres[i]]].push_back({plays[i], i});
    }
    
    sort(sorted_plays, sorted_plays+idx, cmpVpii);
    for (int i=0; i<idx; ++i)
        sort(sorted_plays[i].begin(), sorted_plays[i].end(), cmpPii);
    
    for (int i=0; i<idx; ++i){
        for (int j=1; j<min((unsigned long)3, sorted_plays[i].size()); ++j)
            answer.push_back(sorted_plays[i][j].second);
    }
        
    return answer;
}