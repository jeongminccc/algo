#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int,int>> q;
    
    for (int i=0; i<progresses.size(); ++i)
        q.push({progresses[i], speeds[i]});
    
    int time = 0;
    while (!q.empty()){
        int cntDeployed = 0;
        while (!q.empty() && q.front().first + (time * q.front().second) >= 100){
            q.pop();
            cntDeployed++;
        }
        time++;
        
        if (cntDeployed) answer.push_back(cntDeployed); 
    }
    return answer;
}