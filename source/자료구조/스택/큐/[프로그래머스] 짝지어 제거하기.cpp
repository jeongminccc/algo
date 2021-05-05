#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;
    for (char &c:s){
        if (st.empty() || st.top() != c) st.push(c);
        else st.pop();
    }

    if (st.empty()) answer = 1;
    return answer;
}