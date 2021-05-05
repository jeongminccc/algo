#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string inputString) {
    int answer = 0;
    
    stack<char> st;
    char left_bracket[4] = {'(', '{', '[', '<'};
    char right_bracket[4] = {')', '}', ']', '>'};
    
    int cnt_bracket=0;
    for(int i=0; i<inputString.size(); ++i){
        for (int j=0; j<4; ++j){
            if (inputString[i] == left_bracket[j])
                st.push(inputString[i]);
            
            if (inputString[i] == right_bracket[j]){
                if(st.empty() || left_bracket[j] != st.top())
                    return (-i);
                
                st.pop();
                cnt_bracket++;
            }
        }
    }
    if (!st.empty()) answer = -(inputString.size() - 1); // 열려있는 상태이므로 마지막 인덱스를 음수로 반환
    else answer = cnt_bracket; // 정상적으로 사용, 총 괄호 쌍의 개수를 반환
    
    return (answer);
}