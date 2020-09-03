#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<pair<int, int>> cost(200001);
bool cmpLeft(const pii& a, const pii& b){
    return a.first > b.first;
}

bool cmpRight(const pii& a, const pii& b){
    return a.second < b.second;
}

ll recur(int left, int right){
    if(left + 1 == right) return cost[left].second < cost[right].second ? cost[left].first : cost[right].first;

    vector<pii> newLeft;
    ll ret = 0;
    auto beginLeft = cost.begin()+left;
    auto beginRight = cost.begin()+left+(right/2);
    auto end = cost.begin()+right;
    sort(beginRight, end, cmpRight);
    
    for(auto iter=beginLeft; iter<beginRight; ++iter){
        
        auto minCostIndex = lower_bound(beginRight, end, make_pair(0, (*iter).second), cmpRight);
        
        if(minCostIndex != end){ // B(i)보다 큰 값이 있는 경우
            ret += (*iter).first;
            cost.erase(minCostIndex);
        }
        else{ // B(i)보다 큰 값이 없는 경우
            newLeft.push_back({(*iter).first, (*iter).second}); // 새롭게 만들어질 왼쪽 벡터에 넣어줌.
        }
    }
    // 다 끝난경우 벡터안에 남은 요소들은 새롭게 만들어질 오른쪽 벡터에 들어가야 할 요소들이므로 그대로 쓰면된다.
    
    // 근데 여기서 고려해야 할 점이 홀수개 / 홀수개로 쪼개질때임.
    cost.erase(cost.begin(), cost.begin()+(cost.size()/2));
    sort(cost.begin(), cost.end(), cmpLeft);
    if(newLeft.size() % 2 == 1){
        auto iter = cost.begin();
        newLeft.push_back({(*iter).first, (*iter).second});
        cost.erase(iter);
    }
    
//    for(auto& a:newLeft) cout << a.first << " " << a.second << " ";
//    cout << endl;
//
//    for(auto& a:v) cout << a.first << " " << a.second << " ";
//    cout << endl;
    
    ret += recur(newLeft) + recur(v);

    return ret;
}

int main(){
    cin >> N;
    for(auto& x:cost) cin >> x.first;
    for(auto& x:cost) cin >> x.second;
    
    sort(cost.begin(), cost.end(), cmpLeft);
    ll ans = recur(0,N);
    cout << ans;
    return 0;
}

// 1. A의 cost순으로 내림차순 정렬을 한다.
// 2. 정렬된 값들을 분할정복으로 하나씩 처리 해 줌.
