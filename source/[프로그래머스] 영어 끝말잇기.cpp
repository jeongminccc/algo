#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    set<string> used;
    char before_last = words.front().front();
    for (int i=0; i<words.size(); ++i){
        if ((used.find(words[i]) != used.end()) ||
            (words[i].size() == 1) ||
            (before_last != words[i].front())){
                answer.push_back(1 + (i%n));
                answer.push_back(1 + (i/n));
                return (answer);
            }
        before_last = words[i].back();
        used.insert(words[i]);
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}