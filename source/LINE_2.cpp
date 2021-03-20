#include <string>
#include <vector>
#include <map>

using namespace std;

string special = "~!@#$%^&*";

bool chk_length(const string s){
    return (8 <= s.size() && s.size() <= 15);
}

int chk_char(const string s){
    bool flag, flag_second=true, a=false, b=false, c=false, d=false;

    for (int i=0; i<s.size(); ++i){
        flag = false;

        if ('A' <= s[i] && s[i] <= 'Z') { flag = true; a = true; } 
        if ('a' <= s[i] && s[i] <= 'z') { flag = true; b = true; }
        if ('0' <= s[i] && s[i] <= '9') { flag = true; c = true; }
        for (int j=0; j<special.size(); ++j){
            if (special[j] == s[i]){
                flag = true;
                d = true;
                break;
            }
        }

        if (!flag) flag_second = false;
    }

    if (!flag_second){
        if (a + b + c + d >= 3) return (2);
        else return (0);
    }
    if (a + b + c + d >= 3) return (3);
    return (1);

    // 둘 다 미충족시 0 리턴
    // 2번만 충족시 1 리턴
    // 3번만 충족시 2 리턴
    // 둘 다 충족시 3 리턴 
}

bool chk_cons(const string s){
    char before_char = s[0];
    int cons_cnt = 1;

    for(int i=1; i<s.size(); ++i){
        if (before_char == s[i]) cons_cnt++;
        else {
            before_char = s[i];
            cons_cnt = 1;
        }

        if (cons_cnt >= 4) return false;
    }

    return true;
}

bool chk_over(const string s){
    map<char, int> m;
    for (int i=0; i<s.size(); ++i)
        m[s[i]]++;
    
    for (int i=0; i<s.size(); ++i)
        if (m[s[i]] >= 5) return false;
    
    return true;
}

vector<int> solution(string inp_str) {
    vector<int> answer;

    if (!chk_length(inp_str)) answer.push_back(1);
    if (chk_char(inp_str) == 2) answer.push_back(2);
    if (chk_char(inp_str) == 1) answer.push_back(3);
    if (chk_char(inp_str) == 0) { answer.push_back(2); answer.push_back(3); }
    if (!chk_cons(inp_str)) answer.push_back(4);
    if (!chk_over(inp_str)) answer.push_back(5);
    if (answer.empty()) answer.push_back(0);
    
    return answer;
}