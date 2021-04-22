#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> tmp_array;

    int start, end, target;
    for (int i=0; i<commands.size(); ++i){
        start = commands[i][0] - 1;
        end = commands[i][1];
        target = commands[i][2] - 1;

        tmp_array.assign(array.begin() + start, array.begin() + end);
        sort(tmp_array.begin(), tmp_array.end());
        answer.push_back(tmp_array[target]);
    }
    return answer;
}