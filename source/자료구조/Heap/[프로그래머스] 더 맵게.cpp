#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 1;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (auto &i : scoville) pq.push(i);
    
    while (true){
        if (pq.size() == 1 && pq.top() < K) return (-1);
        
        int new_scoville = pq.top();
        pq.pop();
        new_scoville += 2 * pq.top();
        pq.pop();
        pq.push(new_scoville);
        
        if (pq.top() >= K)
            break;
        answer++;
    }
    
    return answer;
}