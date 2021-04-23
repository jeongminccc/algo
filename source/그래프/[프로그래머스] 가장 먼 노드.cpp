#include <string>
#include <vector>
#include <queue>

using namespace std;
const int max_node = 20001;

vector<int> node[max_node];
bool visited[max_node] = {false};
int max_depth = 0;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i=0; i<edge.size(); ++i){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    
    int cur_node, depth;
    while (!q.empty()){
        cur_node = q.front().first;
        depth = q.front().second;
        q.pop();
        
        if (max_depth == depth) answer++;
        else if (max_depth < depth){
            max_depth = depth;
            answer = 1;
        }
        
        for (int i=0; i<node[cur_node].size(); ++i){
            if (!visited[node[cur_node][i]]){
                q.push({node[cur_node][i], depth + 1});
                visited[node[cur_node][i]] = true;
            }
        }
    }
    
    return answer;
}