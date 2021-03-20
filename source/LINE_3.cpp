#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 1001;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size());
    bool checked[MAX] = {false};

    int next;
    int idx_limit;
    for (int i=0; i<enter.size(); ++i){
        next = i + 1;
        checked[enter[i]] = true;

        for (int j=0; j<leave.size(); ++j){
            if (enter[i] == leave[j]){
                idx_limit = j - 1;
                cout << idx_limit << " " << endl;
                while (idx_limit >= 0 && checked[leave[idx_limit]])
                    idx_limit--;
                break;
            }
        }
        cout << idx_limit << endl;
        
        if (idx_limit < 0) continue;
        
        for (int j=next; j<enter.size(); ++j){
            for(int k=0; k<=idx_limit; ++k){
                if (enter[j] == leave[k]){
                    if (!checked[leave[k]]){
                        answer[enter[i] - 1]++;
                        answer[leave[k] - 1]++;
                    }
                    break;
                }
            }
        }
    }
    return answer;
}