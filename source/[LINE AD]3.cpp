#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> ads) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    sort(ads.begin(), ads.end());
    
    int time = ads[0][0];
    while (!ads.empty() || !pq.empty()){
        while (!ads.empty() && ads[0][0] <= time){
            pq.push({ads[0][1] , ads[0][0]});
            ads.erase(ads.begin());
        }
        
        if (!pq.empty()){
            answer += (pq.top().first * (time - pq.top().second));
            time += 5;
            pq.pop();
        }
        else time++;
    }
    return answer;
}