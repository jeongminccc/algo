#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string g_answer = "a";
bool visited[10001] = {false};

void findMinRoute(vector<vector<string>> &tickets, string temp_ans, string pos, int cnt){
    if (cnt == tickets.size()){
        if (g_answer > temp_ans){ // 아스키코드 사전순으로 정렬하기 때문에 a > ICN...
            g_answer = temp_ans;
        }
        return ;
    }

    for (int i=0; i<tickets.size(); ++i){
        if (!visited[i] && pos == tickets[i][0]){
            visited[i] = true;
            findMinRoute(tickets, temp_ans + tickets[i][1], tickets[i][1], cnt + 1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer; 

    findMinRoute(tickets, "ICN", "ICN", 0);

    for (int i=0; i<g_answer.size(); i+=3){
        answer.push_back(g_answer.substr(i, 3));
    }
    return answer;
}