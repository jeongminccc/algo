//
//  카카오 블라인드 채용 2020 F 블록 이동하기.cpp
//  algo
//
//  Created by jm on 2020/09/11.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;
typedef vector<vector<int>> vvi;
int dx[8][2] = {{0,1}, {0,1}, {1,1},   {-1, 0}, {-1, 0}, {-1, -1}, {0,0}, {0,0} };
int dy[8][2] = {{0,-1}, {1,0}, {0,0},   {0, -1}, {1, 0}, {0, 0},  {1,1}, {-1,-1} };

int lx[4][2] = {{0,-1}, {1,0},    {0,-1}, {1, 0}};
int ly[4][2] = {{0,1}, {0,1},     {-1,0} ,{-1, 0}};

int N;
queue<string> q;
set<string> visit;

bool check(int x1, int y1, int x2, int y2){
    return x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x1 < N && y1 < N && x2 < N && y2 < N;
}

void PushStr(string input){
//    cout << input << endl;
    int x1 = input[0] - '0' , y1 = input[1] - '0' , x2 = input[2] - '0' , y2 = input[3] - '0';
    
    if(check(x1,y1,x2,y2) && visit.find(input) == visit.end()){
        q.push(input);
        visit.insert(input);
    }
}

int Solve(vvi& board){
    
    q.push("0001"); // x1,y1,x2,y2;
   visit.insert("0001");
    int cur = 0;
    
   while(!q.empty()){
       int size = (int)q.size();
       
       for(int k=0; k<size; ++k){
           int x1 = q.front()[0] - '0' , y1 = q.front()[1] - '0' , x2 = q.front()[2] - '0' , y2 = q.front()[3] - '0';
           string s = q.front();
           q.pop();
//           cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
           
           if( (x1 == N-1 && y1 == N-1) || (x2 == N-1 && y2 == N-1)) return cur;
           
           if(x1 == x2 && y2 == y1+1){ // 0--0 와 같은 모양인 경우
               if(x1+1 < N && (board[x1+1][y1] == 0 && board[x2+1][y2] == 0)){ // 밑의 두칸이 모두 0일때
                   for(int i=0; i<3; ++i){
                       string input = to_string(x1+dx[i][0]) + to_string(y1+dy[i][0]) + to_string(x2+dx[i][1]) + to_string(y2+dy[i][1]);
                       PushStr(input);
                   }
               }
               if(x1-1 >= 0 && (board[x1-1][y1] == 0 && board[x2-1][y2] == 0)){ // 위의 두칸이 모두 0일때
                   for(int i=3; i<6; ++i){
                       string input = to_string(x1+dx[i][0]) + to_string(y1+dy[i][0]) + to_string(x2+dx[i][1]) + to_string(y2+dy[i][1]);
                       PushStr(input);
                   }
               }
               if(y2+1 < N && (board[x2][y2+1] == 0)){ // 오른쪽으로 이동
                   string input = to_string(x1+dx[6][0]) + to_string(y1+dy[6][0]) + to_string(x2+dx[6][1]) + to_string(y2+dy[6][1]);
                   PushStr(input);
               }
               if(y1-1 >= 0 && (board[x1][y1-1] == 0)){ // 왼쪽으로 이동
                   string input = to_string(x1+dx[7][0]) + to_string(y1+dy[7][0]) + to_string(x2+dx[7][1]) + to_string(y2+dy[7][1]);
                   PushStr(input);
               }
           }
           else if(y1 == y2 && x2 == x1+1){ // ㅣ 과 같은 모양인 경우
               if(y1+1 < N && (board[x1][y1+1] == 0 && board[x2][y2+1] == 0)){ // 오른쪽이 비었을때
                   for(int i=0; i<=1; ++i){
                       string input = to_string(x1+lx[i][0]) + to_string(y1+ly[i][0]) + to_string(x2+lx[i][1]) + to_string(y2+ly[i][1]);
                       PushStr(input);
                   }
                   string input = to_string(x1+dx[6][0]) + to_string(y1+dy[6][0]) + to_string(x2+dx[6][1]) + to_string(y2+dy[6][1]);
                   PushStr(input);
               }
               
               if(y1-1 >= 0 && (board[x1][y1-1] == 0 && board[x2][y2-1] == 0)){ // 왼쪽이 비었을때
                   for(int i=2; i<4; ++i){
                       string input = to_string(x1+lx[i][0]) + to_string(y1+ly[i][0]) + to_string(x2+lx[i][1]) + to_string(y2+ly[i][1]);
                       PushStr(input);
                   }
                   string input = to_string(x1+dx[7][0]) + to_string(y1+dy[7][0]) + to_string(x2+dx[7][1]) + to_string(y2+dy[7][1]);
                   PushStr(input);
               }
               
               if(x1-1 >= 0 && board[x1-1][y1] == 0){ // 위로
                   string input = to_string(x1+dx[5][0]) + to_string(y1+dy[5][0]) + to_string(x2+dx[5][1]) + to_string(y2+dy[5][1]);
                   PushStr(input);
               }
               
               if(x2+1 < N && board[x2+1][y2] == 0){ // 아래로
                   string input = to_string(x1+dx[2][0]) + to_string(y1+dy[2][0]) + to_string(x2+dx[2][1]) + to_string(y2+dy[2][1]);
                   PushStr(input);
               }
           }
       }
       cur++;
   }
    return cur;
}

int solution(vector<vector<int>> board) {
    N = (int)board.size();
    int answer = 0;
    
    answer = Solve(board);
    return answer;
}

int main(){
    vector<vector<int>> v = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};

    cout << solution(v);
    return 0;
}
