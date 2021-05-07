#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int skill_idx;
    bool is_ordered;
    for (int i=0; i<skill_trees.size(); ++i){
        skill_idx = 0;
        is_ordered = true;
        for (int j=0; j<skill_trees[i].size(); ++j){
            if (skill.find(skill_trees[i][j]) != string::npos){
                if (skill_idx != skill.find(skill_trees[i][j])) is_ordered = false;
                else skill_idx++;
            }
        }
        if (is_ordered) {
            answer++;
        }
    }


    return (answer);
}