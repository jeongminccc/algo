#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> p;
    for(string &s : completion) p[s]++;
    
    for(string &s : participant){
        if (p[s] == 0){
            answer = s;
            break ;
        }
        p[s]--;
    }
    
    return answer;
}