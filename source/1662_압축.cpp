#include <iostream>

using namespace std;

string S;
int cur = 0;

int recur(){
    int ret = 0;

    while (S[cur]){
        if (S[cur] == ')') return (ret);

        if ((S[cur + 1] && S[cur + 1] != '(') || !S[cur + 1])
            ret += 1;
        else{
            cur += 2;
            ret += (S[cur - 2] - '0') * recur();
        }
        cur++;
    }
    return (ret);
}

int main(){
    cin >> S;

    cout << recur();
    return (0);
}