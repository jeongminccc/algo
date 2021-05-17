#include <string>
#include <vector>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

void init(set<int> &table, int n){
    for (int i=0; i<n; ++i)
        table.insert(i);
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    set<int> table;
    stack<int> removed;
    init(table, n);

    int num_to_move;
    auto pos_iter = table.find(k), tmp_iter = table.begin();
    for (int i=0; i<cmd.size(); ++i){
        if (cmd[i].front() == 'U'){
            num_to_move = stoi(cmd[i].substr(2));
            for (int j=0; j<num_to_move; ++j)
                pos_iter--;
        }
        else if (cmd[i].front() == 'D'){
            num_to_move = stoi(cmd[i].substr(2));
            for (int j=0; j<num_to_move; ++j)
                pos_iter++;
        }
        else if (cmd[i].front() == 'C'){
            tmp_iter = pos_iter++;
            if (pos_iter == table.end()) {pos_iter--; pos_iter--;}
            removed.push(*tmp_iter);
            table.erase(tmp_iter);
        }
        else if (cmd[i].front() == 'Z'){
            table.insert(removed.top());
            removed.pop();
        }
    }

    pos_iter = table.begin();
    bool is_end_table = false;
    for (int i=0; i<n; ++i){
        if (is_end_table || *pos_iter != i)
            answer += "X";
        else {
            if (++pos_iter == table.end()) is_end_table = true;
            answer += "O";
        }
    }
    return answer;
}

// 테이블 주고 위아래로 왔다갔다하며 삭제