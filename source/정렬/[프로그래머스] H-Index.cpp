#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int h=0; h<=citations.back(); ++h){
        int under_cnt = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        if (under_cnt <= h && citations.size() - under_cnt >= h){
            answer = max(answer,h);
        }
    }
    
    return answer;
}