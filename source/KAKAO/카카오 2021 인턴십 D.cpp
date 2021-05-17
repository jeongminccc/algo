#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxNum = 1e9;
const int nodeMax = 1001;

struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return (a.second > b.second);
    }
};

struct NodeInfo{
    int target;
    int cost;
    bool isStart; // true = go to target, false = arrived from target
};

void reverseDir(vector<NodeInfo> node[], int &n, int &trap){
    for (int i=1; i<=n; ++i){
        for (int j=0; j<node[i].size(); ++j){
            if (node[i][j].target == trap){
                node[i][j].isStart ^= 1;
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = maxNum;

    vector<NodeInfo> node[nodeMax];
    for (auto vi:roads){
        node[vi[0]].push_back({vi[1], vi[2], true}); // 0 = start, 1 = end, 2 = cost
        node[vi[1]].push_back({vi[0], vi[2], false});
    }

    int visited[nodeMax] = {0};
    for (int i=0; i<nodeMax; ++i) visited[i] = maxNum;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // start, sum of cost
    pq.push({start, 0});
    visited[start] = 0;

    int cur, cost;
    bool isTrap;
    while (!pq.empty()){
        cur = pq.top().first;
        cost = pq.top().second;
        pq.pop();

        if (cur == end || cost >= answer){
            if (answer > cost) answer = cost;
            continue;
        }
        
        if (find(traps.begin(), traps.end(), cur) != traps.end()){ // case #trap
            reverseDir(node, n, cur);
            
            for (int i=0; i<node[cur].size(); ++i)
                node[cur][i].isStart ^= 1;
        }

        for (int i=0; i<node[cur].size(); ++i){
            isTrap = false;
            if (find(traps.begin(), traps.end(), node[cur][i].target) != traps.end())
                isTrap = true;

            if (node[cur][i].isStart &&
                ((visited[node[cur][i].target] >= cost + node[cur][i].cost) || isTrap)){ // case# Only go to target
                    pq.push({node[cur][i].target, cost + node[cur][i].cost});
                    visited[node[cur][i].target] = cost + node[cur][i].cost;
            }
        }
    }

    
    return answer;
}

// 노드들이 있고 Trap을 지나면 방향이 반대가 됨