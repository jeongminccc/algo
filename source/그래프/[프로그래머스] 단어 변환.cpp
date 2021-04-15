#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;
const int MAX = 1e9;

int g_answer = MAX;
string g_target;

int cntDiff(string a, string b){
    int ret = 0;

    for (int i=0; i<a.size(); ++i){
        if (a[i] != b[i]) ret++;
    }
    return (ret);
}

void cntSteps(string pos, bool visited[], vector<string> &words, int cnt){
    if (pos == g_target){
        g_answer = min(g_answer, cnt);
        return ;
    }
    
    for (int i=0; i<words.size(); ++i){
        if (!visited[i] && cntDiff(pos, words[i]) == 1){
            visited[i] = true;
            cntSteps(words[i], visited, words, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    g_target = target;
    bool visited[51] = {false};

    for (int i=0; i<words.size(); ++i){
        memset(visited, 0, sizeof(visited));
        if (cntDiff(begin, words[i]) == 1){
            visited[i] = true;
            cntSteps(words[i], visited, words, 1);
        }
    }

    if (g_answer == MAX) answer = 0;
    else answer = g_answer;

    return answer;
}