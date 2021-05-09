#include <string>
#include <vector>
#include <map>

using namespace std;

void init(map<string,char> &m){
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
}

int solution(string s) {
    int answer = 0;
    map<string,char> alpha_to_num;
    init(alpha_to_num);

    string str_answer="", tmp_alpha="";
    for (char &c:s){
        if ('0' <= c && c <= '9') str_answer += c;
        else{
            tmp_alpha += c;
            if (alpha_to_num.find(tmp_alpha) != alpha_to_num.end()){
                str_answer += alpha_to_num[tmp_alpha];
                tmp_alpha = "";
            }
        }
    }

    answer = stoi(str_answer);
    return answer;
}