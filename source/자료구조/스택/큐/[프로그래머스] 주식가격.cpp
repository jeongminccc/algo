#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>> > pq;
    
    for (int i=0; i<prices.size(); ++i){
        while (!pq.empty() && pq.top().first > prices[i]){
            answer[pq.top().second] = i - pq.top().second;
            pq.pop();
        }
        pq.push({prices[i], i});
    }
    while (!pq.empty()){
        answer[pq.top().second] = prices.size() - pq.top().second - 1;
        pq.pop();
    }
    
    return answer;
}