#include <string>
#include <set>

using namespace std;

set<pair<pair<int,int>,pair<int,int>>> visited;

bool isValid(int x, int y){
    return (-5 <= x && x <= 5 && -5 <= y && y <= 5);
}

void isNewRoute(int l_x, int l_y, int r_x, int r_y){
        
    if (visited.find({{l_x, l_y},{r_x,r_y}}) == visited.end() &&
        visited.find({{r_x, r_y},{l_x, l_y}}) == visited.end()){ // 처음가는 길이면
        visited.insert({{l_x, l_y},{r_x, r_y}});
    }
}

int solution(string dirs) {

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int pos_x=0, pos_y=0, to_x, to_y, idx = 0;
    for (char &c:dirs){
        if (c == 'L') idx = 0;
        else if (c == 'U') idx = 1;
        else if (c == 'R') idx = 2;
        else if (c == 'D') idx = 3;

        to_x = pos_x + dx[idx];
        to_y = pos_y + dy[idx];

        if (isValid(to_x, to_y)){
            isNewRoute(to_x, to_y, pos_x, pos_y);
            pos_x = to_x;
            pos_y = to_y;
        }
    }

    return (int(visited.size()));
}