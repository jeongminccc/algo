#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int answer = 0;
    int n = 0;
    int time = jobs[0][0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    
    while (!jobs.empty()) {
        auto job = jobs[0];
        jobs.erase(jobs.begin());
        n += 1;
        time += job[1];
        answer += (time - job[0]);
        
        while (!jobs.empty() && jobs[0][0] < time) {
            auto job = jobs[0];
            jobs.erase(jobs.begin());
            pq.push(make_pair(job[1], job[0]));
        }
        
        while (!pq.empty()) {
            auto job = pq.top();
            jobs.insert(jobs.begin(), vector<int>{ job.second, job.first });
            pq.pop();
        }
    }
    
    answer /= n;
    return answer;
}