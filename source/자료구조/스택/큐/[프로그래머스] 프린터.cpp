#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for (int i=0; i<priorities.size(); ++i){
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    
    int order = 1;
    while (!q.empty()){
        if (pq.top() == q.front().first){
            pq.pop();
            if (q.front().second == location){
                answer = order;
                break;
            }
            order++;
        }
        q.push(q.front());
        q.pop();
    }
    return answer;
}