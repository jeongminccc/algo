#include <string>
#include <vector>
#include <queue>

using namespace std;
const int mapSize = 5;

int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

bool isInMap(int y, int x){
    return (0 <= y && y < mapSize && 0 <= x && x < mapSize);
}

bool checkInDistance(string map[], int y, int x){
    bool visited[mapSize][mapSize] = {false};
    queue<pair<pair<int,int>,int>> q;
    q.push({{y,x},0});
    visited[y][x] = true;

    int nx,ny,distance;
    while(!q.empty()){
        y = q.front().first.first;
        x = q.front().first.second;
        distance = q.front().second;
        q.pop();
        
        if (distance >= 2) continue;

        for (int i=0; i<4; ++i){
            ny = y+dy[i], nx = x+dx[i];
            if (isInMap(ny,nx) && !visited[ny][nx] && map[ny][nx] != 'X'){
                if (map[ny][nx] == 'P') return (false);

                q.push({{ny,nx}, distance+1});
                visited[ny][nx] = true;
            }
        }
    }
    return (true);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    string map[mapSize];
    for (int i=0; i<mapSize; ++i){
        for (int j=0; j<mapSize; ++j)
            map[j] = places[i][j];

        bool isKeepDistance=true;
        for (int j=0; j<mapSize; ++j){
            for (int k=0; k<mapSize; ++k){
                if (map[j][k] == 'P'){
                    if (!checkInDistance(map, j, k)){
                        isKeepDistance = false;
                        break;
                    }
                }
            }
            if (!isKeepDistance) break;
        }

        if (!isKeepDistance) answer.push_back(0);
        else answer.push_back(1);
    }

    return answer;
}