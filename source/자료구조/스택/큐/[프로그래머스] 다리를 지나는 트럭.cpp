#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int bridges[10001] = {0};
    int cur_weight, time = 1, cur_truck = 0;
    while (1){
        cur_weight = 0;
        for (int i=(bridge_length - 1); i>=1; --i){
            cur_weight += bridges[i];
            bridges[i+1] = bridges[i];
        }
        bridges[1] = 0;
        
        if (cur_weight + truck_weights[cur_truck] <= weight){
            bridges[1] = truck_weights[cur_truck];
            cur_weight += bridges[1];
            cur_truck++;
        }
        
        if (cur_weight == 0 && cur_truck >= truck_weights.size())
            break;
        
        time++;
    }
    
    answer = time;
    return answer;
}