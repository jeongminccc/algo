#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int visited[26][26];
    for (int i=0; i<26; ++i)
        for (int j=0; j<26; ++j)
            visited[i][j] = 1e9;
    
    visited[0][0] = 0;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});

    int x,y,prev_mov,cost,dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
    while (!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        prev_mov = q.front().second.first;
        cost = q.front().second.second;
        q.pop();

        int nx,ny,n_cost;
        for (int i=0; i<4; ++i){
            nx = x+dx[i], ny = y+dy[i];
            n_cost = cost + 100;
            if (prev_mov != i/2 && !(x==0 && y==0)) n_cost += 500;

            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board.size() &&
                !board[nx][ny] && (visited[nx][ny] >= n_cost) ){
                    q.push({{nx,ny}, {i/2, n_cost}});
                    visited[nx][ny] = n_cost;
            }
        }
    }

    answer = visited[board.size()-1][board.size()-1];
    return answer;
}