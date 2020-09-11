//
//  카카오 블라인드 채용 2020 C 자물쇠와 열쇠.cpp
//  algo
//
//  Created by jm on 2020/09/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> vvi;

vvi TurnRight(vvi v, int l){
    for(int k=0; k<l; ++k){
        vvi temp(v);
        
        for(int i=0; i<v.size(); ++i)
            for(int j=0; j<v.size(); ++j)
                v[i][j] = temp[v.size()-j-1][i];
    }
    return v;
}
vvi MoveUp(vvi v, int u){
    for(int i=0; i<v.size(); ++i)
        for(int j=0; j<v.size(); ++j){
            if(i >= v.size()-u) v[i][j] = 0;
            else v[i][j] = v[i+u][j];
        }
    return v;
}
vvi MoveDown(vvi v, int d){
    for(int i=v.size()-1; i>=0; --i)
        for(int j=0; j<v.size(); ++j){
            if(i < d) v[i][j] = 0;
            else v[i][j] = v[i-d][j];
        }
    return v;
}
vvi MoveLeft(vvi v, int l){
    for(int j=0; j<v.size(); ++j)
        for(int i=0; i<v.size(); ++i){
            if(j >= v.size()-l) v[i][j] = 0;
            else v[i][j] = v[i][j+l];
        }
    return v;
}
vvi MoveRight(vvi v, int r){
    for(int j=v.size()-1; j>=0; --j)
        for(int i=0; i<v.size(); ++i){
            if(j < r) v[i][j] = 0;
            else v[i][j] = v[i][j-r];
        }
    return v;
}
bool IsCorrect(vvi k, vvi ans){
    for(int i=0; i<ans.size(); ++i)
        for(int j=0; j<ans.size(); ++j)
            if(k[i][j] == ans[i][j]) return false;
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vvi temp(lock);
    for(int i=0; i<lock.size(); ++i)
        for(int j=0; j<lock.size(); ++j)
            temp[i][j] = 0;
    
    for(int i=0; i<key.size(); ++i)
        for(int j=0; j<key.size(); ++j)
            temp[i][j] = key[i][j];
    
    for(int i=0; i<4; ++i){ // 오른쪽으로 i번 회전
        vvi test = TurnRight(temp,i);
        
        for(int j=0; j<lock.size(); ++j){ // 위로 j칸
            vvi testForUp = MoveUp(test, j);
            
            for(int k=0; k<lock.size(); ++k) // 오른쪽으로 k칸
                if(IsCorrect(MoveRight(testForUp, k), lock)) return true;
            
            for(int k=0; k<lock.size(); ++k) // 왼쪽으로 k칸
                if(IsCorrect(MoveLeft(testForUp, k), lock)) return true;
        }
        
        for(int j=0; j<lock.size(); ++j){ // 아래로 j칸
            vvi testForDown = MoveDown(test, j);
            
            for(int k=0; k<lock.size(); ++k) // 오른쪽으로 k칸
                if(IsCorrect(MoveRight(testForDown, k), lock)) return true;
            
            for(int k=0; k<lock.size(); ++k) // 왼쪽으로 k칸
                if(IsCorrect(MoveLeft(testForDown, k), lock)) return true;
        }
    }
    
    return false;
}

int main(){
    vector<vector<int>> v = {{0,0,1}, {1,0,0}, {1,0,0}};
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << v[i][j] << " ";
        }cout << endl;
    }
    cout << endl;
    vvi temp = MoveLeft(v, 3);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << temp[i][j] << " ";
        }cout << endl;
    }
    
    return 0;
}
