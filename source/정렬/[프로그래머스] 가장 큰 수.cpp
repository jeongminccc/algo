#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b){
    string s_a = to_string(a);
    string s_b = to_string(b);

    return (stoi(s_a + s_b) > stoi(s_b + s_a));
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);
    for (auto &num : numbers) answer += to_string(num);

    if (atoi(answer.c_str()) == 0) answer = "0";
    return answer;
}