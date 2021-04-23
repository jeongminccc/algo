#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, bool> m;
    for (string &s : phone_book)
        m[s] = true;
    
    string tmp;
    for (string &s : phone_book){
        tmp = "";
        for (int i=0; i<s.size(); ++i){
            tmp += s[i];
            if (m[tmp] && tmp != s)
                return (false);
        }
    }
    
    
    return answer;
}