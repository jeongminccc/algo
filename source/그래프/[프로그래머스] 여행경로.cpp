#include <string>
#include <vector>
#include <map>

using namespace std;

map<string ,int> tks;
int routes[10001][2];
bool visited[10001] = {false};

void findMinRoute(vector<string> &answer, vector<string> &temp_ans, int pos, int size){

    string input; 
    for (int i=0; i<size; ++i){
        if (!visited[i] && routes[pos][1] == routes[i][0]){
            visited[i] = true;
            input = 
            temp_ans.push_back()
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer; 
    
    int pos = 1;
    for (int i=0; i<tickets.size(); ++i){ // 각각 번호 부여, map에 저장
        for (int j=0; j<2; ++j){
            if (tks.find(tickets[i][j]) == tks.end()){
                tks[tickets[i][j]] = pos++;
            }
        }
    }

    for (int i=0; i<tickets.size(); ++i){
        routes[i][0] = tks[tickets[i][0]];
        routes[i][1] = tks[tickets[i][1]];
    }
    
    vector<string> temp_ans;
    findMinRoute(answer, temp_ans, 0, tickets.size());

    return answer;
}