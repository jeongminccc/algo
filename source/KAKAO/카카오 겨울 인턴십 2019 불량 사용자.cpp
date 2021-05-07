#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

set<vector<string>> used;
map<string, int> visited;

bool isValid(string &banned, string &user){
    if (banned.size() == user.size()){
        for (int i=0; i<banned.size(); ++i){
            if (banned[i] != '*' && banned[i] != user[i])
                return (false);
        }
        return (true);
    }
    return (false);
}

void cntList(vector<string> &user_id, vector<string> &banned_id, vector<string> &tmp, int pos){
    if (tmp.size() == banned_id.size()){
        vector<string> ins(tmp);
        sort(ins.begin(), ins.end());
        used.insert(ins);
        return ;
    }
    
    for (int i=pos; i<banned_id.size(); ++i){
        for (int j=0; j<user_id.size(); ++j){
            if(isValid(banned_id[i], user_id[j]) && !visited[user_id[j]]) 
            {
                visited[user_id[j]] = 1;
                tmp.push_back(user_id[j]);
                cntList(user_id, banned_id, tmp, i+1);
                tmp.pop_back();
                visited[user_id[j]] = 0;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 1;

    vector<string> tmp;
    cntList(user_id, banned_id, tmp, 0);

    answer = used.size();
    return answer;
}