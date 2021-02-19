//
//  카카오 블라인드 채용 2020 E 기둥과 보 설치.cpp
//  algo
//
//  Created by jm on 2020/09/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
const int MAX_N = 101;

int N, map[MAX_N][MAX_N]; // 0은 아무것도 없음, 1은 기둥, 2는 보

void BuildColumn(int x, int y){
    if(x == N || map[x+1][y] == 1 || map[x][y-1] == 2){ // 바닥이거나 보 or 기둥 위 인지
        map[x][y] = 1;
    }
}
void BuildFlat(int x, int y){
    if(map[x+1][y] == 1 || map[x+1][y+1] == 1 || (map[x][y-1] == 2 && map[x][y+1] == 2)) // 기둥 위거나 보 사이인지
        map[x][y] = 2;
}
void DeleteColumn(int x, int y){
     // 위에 기둥&보가 없고, 좌측 위편에 보가 없는 경우
    if(map[x-1][y] == 0 && map[x-1][y-1] != 2) map[x][y] = 0;
    
    // 자신의 위에 보가 있고, 양쪽과 연결되거나 오른쪽에 기둥이 있는경우
    else if(map[x-1][y] == 2 && ((map[x-1][y-1] == 2 && map[x-1][y+1] == 2) || map[x][y+1] == 1)) map[x][y] = 0;
    
    // 자신의 좌측 위편에 보가 있고, 양쪽과 연결되거나 왼쪽에 기둥이 있는경우
    else if(map[x-1][y] != 1 && map[x-1][y-1] == 2 && ((map[x-1][y-2] == 2 && map[x-1][y] == 2) || map[x][y-1] == 1)) map[x][y] = 0;
}
void DeleteFlat(int x, int y){
    // 오른쪽에 기둥&보가 없고, 왼쪽에 보가 없는경우
    if(map[x][y+1] == 0 && map[x][y-1] != 2) map[x][y] = 0;
    
    // 왼쪽은 문제 x 오른쪽에 보가 있고, 버틸수 있는경우
    else if(map[x][y-1] != 2 && map[x][y+1] == 2 && (map[x+1][y+1] == 1 || map[x+1][y+2] == 1)) map[x][y] = 0;
    
    // 오른쪽은 문제 x 왼쪽에 보가 있고, 버틸수 있는경우
    else if(map[x][y+1] == 0 && map[x][y-1] == 2 && map[x+1][y-1] == 1) map[x][y] = 0;
    
    // 왼쪽과 오른쪽에 보가있고, 버틸수 있는 경우
    else if( map[x][y+1] == 2 && (map[x+1][y+1] == 1 || map[x+1][y+2] == 1) && map[x][y-1] == 2 && map[x+1][y-1] == 1) map[x][y] = 0;
}

bool cmp(vi& a, vi& b){ // answer 정렬 (x, y, 기둥 순)
    auto iterA = a.begin(), iterB = b.begin();
    
    if(iterA++ < iterB++) return true;
    if(iterA++ < iterB++) return true;
    return iterA < iterB;
}

vector<vector<int>> solution(int n, vvi build_frame) {
    vvi answer;
    N = n;
    for(int i=0; i<build_frame.size(); ++i){
        int y = build_frame[i][0], x = n - build_frame[i][1];
        int isFlat = build_frame[i][2], isBuild = build_frame[i][3];
        
        if(isBuild){ // 설치
            if(isFlat) // 보 설치
                BuildFlat(x, y);
            else // 기둥 설치
                BuildColumn(x, y);
        }
        
        else{ // 삭제
            if(isFlat) // 보 설치
                DeleteFlat(x, y);
            else // 기둥 설치
                DeleteColumn(x, y);
        }
    }
    
    // map 순회하면서 answer에 정답넣고 정렬후 리턴
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=n; ++j){
            if(map[i][j] != 0) answer.push_back({j,n-i,map[i][j]-1});
        }
    }
    sort(answer.begin(), answer.end());
    
//    for(int i=0; i<answer.size(); i++){
//        for(int j=0; j<answer[i].size(); j++){
//            cout << answer[i][j] << " ";
//        }cout << endl;
//    }
    return answer;
}

int main(){
    vector<vector<int>> v = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    
//    5, [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]
    
    solution(5, v);
    return 0;
}

