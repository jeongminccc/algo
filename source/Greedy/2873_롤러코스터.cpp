//
//  2873_롤러코스터.cpp
//  algo
//
//  Created by jm on 2020/09/02.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int R,C, arr[1001][1001], minPleasure = 1e9, min_i=0, min_j=0;

int main(){
    cin >> R >> C;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin >> arr[i][j];
            if( ((i+j) % 2 == 1) && minPleasure >= arr[i][j]){
                minPleasure = arr[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    
    if(R % 2 == 1){ // R혹은 C가 홀수일때 -> 모든 롤러코스터를 다 탈 수있음.
        for(int i=0; i<R; ++i){
            for(int j=0; j<C-1; ++j){
                if(i%2 == 0) cout << "R";
                else cout << "L";
            }
            if(i != R-1) cout << "D";
        }
    }else if(C % 2 == 1){
        for(int j=0; j<C; ++j){
            for(int i=0; i<R-1; ++i){
                if(j%2 == 0) cout << "D";
                else cout << "U";
            }
            if(j != C-1) cout << "R";
        }
    }else{ // R, C 모두 짝수일때 -> 무조건 하나의 롤러코스터는 타지 못함.
        // 1. i + j % 2 == 1인 칸중 최소칸을 찾는다.
        // 2. 그 칸이 포함된 2줄에 대해 따로 처리.
        // 3. 그 칸이 포함되지 않은 다른 칸들에 대해서는 모두 DDDDRUUUUR 같은 패턴나오도록.
        bool flag = false; // 왼쪽위에서 시작하는지 왼쪽 아래에서 시작하는지
        for(int j=0; j<C; j+=2){
            
            if(j != min_j && j+1 != min_j && !flag){ // 3번의 경우이며, 왼쪽 위에서 시작 할 경우
                for(int i=0; i<R-1; ++i) cout << "D";
                cout << "R";
                
                for(int i=0; i<R-1; ++i) cout << "U";
                cout << "R";
            }
            
            else if(j != min_j && j+1 != min_j && flag){ // 3번의 경우이며, 왼쪽 아래에서 시작 할 경우
                for(int i=0; i<R-1; ++i) cout << "U";
                cout << "R";
                
                for(int i=0; i<R-1; ++i) cout << "D";
                if(j == C - 2) return 0; // 도착
                cout << "R";
            }
            
            else{ // 2번의 경우이며, 무조건 왼쪽 위에서 시작
                bool flag_min = false;
                int temp_j = j;
                for(int i=0; i<R; ++i){
                    if(i == R - 1 && temp_j == C - 1) return 0; // 도착
                    if(i == R - 1 && !flag_min){ // 마지막 줄 까지 왔는데 아직 최솟값 칸을 못만난 경우 -> 이미 왼쪽 젤 끝칸까지 옴
                        cout << "R";
                        break;
                    }
                    
                    if(flag_min){ // 이미 최솟값 칸을 만나 방향이 바뀐경우
                        if(i % 2 == 0){
                            cout << "L";
                            temp_j--;
                        }else{
                            cout << "R";
                            temp_j++;
                        }
                        
                        if(i == R - 1 && temp_j == C - 1) return 0;
                        else if(i == R - 1) cout << "R";
                        else cout << "D";
                    }
                    
                    if(!flag_min){ // 아직 정상적인 방향으로 진행될 시
                        if(i % 2 == 0 && temp_j + 1 == min_j && i == min_i){ // R으로 가야될 칸이 최솟값 칸일때
                            cout << "D";
                            flag_min = true;
                        }else if(i % 2 == 0){
                            cout << "R";
                        }else if(i % 2 == 1 && temp_j - 1 == min_j && i == min_i){ // L으로 가야될 칸이 최솟값 칸일때
                            cout << "D";
                            flag_min = true;
                        }else{
                            cout << "L";
                        }
                        
                        if(!flag_min){ // 이전에서 최솟값 칸을 만나지 않았기때문에, 정상적으로 진행 & 여기서는 최솟값 칸을 만날일이 없음
                            
                            if(i == R - 1 && temp_j == C - 1) return 0;
                            else cout << "D";
                            
                            if(i % 2 == 0) temp_j++;
                            else temp_j--;
                        }
                    }
                }
                flag = true;
            }
        }
    }
    return 0;
}
