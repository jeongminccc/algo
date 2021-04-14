#include <string>
#include <vector>

using namespace std;

void findNetwork(vector<vector<int>>& computers, bool visited[], int pos){
    visited[pos] = true;

    for (int i=0; i<computers[pos].size(); ++i){
        if (computers[pos][i] && !visited[i]){
            findNetwork(computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[200] = {false};

    for (int i=0; i<n; ++i){
        if (!visited[i]){
            findNetwork(computers, visited, i);
            answer++;
        }
    }


    return answer;
}