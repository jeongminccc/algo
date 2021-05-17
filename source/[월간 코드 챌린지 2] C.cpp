#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    size_t idx=0, target=0;
    string tmp_ans;
    for (int k=0; k<s.size(); ++k){
        idx=0;
        tmp_ans = "";
        while (idx < s[k].size()-2){
            target = -1;
            // 남은 문자열에서 110을 찾고 지움
            for (int i=idx; i<s[k].size()-2; ++i){ 
                if (s[k].substr(i,3) == "110") {
                    target = i;
                    s[k].erase(i, 3);
                    break;
                }
            }

            if (target == -1){ // 110을 못찾은 경우
                tmp_ans += s[k].substr(target, s[k].size());
                break;
            }

            if (idx >= s[k].size()-2){ // 110을 제외한 나머지 문자열의 길이가 2이하인 경우
                for (int i=idx; i<s[k].size(); ++i){
                    if (s[k][i] == '0') tmp_ans += "0";
                    else {
                        idx = i;
                        break;
                    }
                }
                tmp_ans += "110";
                if (idx != s[k].size())
                    tmp_ans += s[k].substr(idx, 3);,
            }

            // 110을 넣을 자리를 찾는다.
            for (int i=idx; i<s[k].size()-2; ++i){
                if (s[k].substr(i,3) <= "110") {// 110보다 사전적으로 앞일때
                    if (i == s[k].size()-3){
                        tmp_ans += s[k].substr(i,3) + "110"; // 마지막인 경우
                        idx = s[k].size()-2;
                    }
                    else tmp_ans += s[k][i];
                }
                else{ // 110을 넣을 자리를 찾았을 때
                    idx = i;
                    tmp_ans += "110";
                }
            }
        }
        answer.push_back(tmp_ans);
    }
    return answer;
}