#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer(array.size(), -1);
    
    int tmp_idx;
    for (int i=0; i<array.size(); ++i){
        tmp_idx = i-1;
        while (tmp_idx >= 0 && array[tmp_idx] < array[i]){
            if (array[tmp_idx] < array[i] && 
                ((abs(tmp_idx - answer[tmp_idx]) > abs(tmp_idx - i)) ||
                (answer[tmp_idx] == -1)))
                answer[tmp_idx] = i;
            tmp_idx--;
        }
        
        tmp_idx = i+1;
        while (tmp_idx < array.size() && array[tmp_idx] < array[i]){
            if (array[tmp_idx] < array[i] &&
                ((abs(tmp_idx - answer[tmp_idx]) > abs(tmp_idx - i)) ||
                (answer[tmp_idx] == -1)))
                answer[tmp_idx] = i;
            tmp_idx++;
        }
    }
    return answer;
}