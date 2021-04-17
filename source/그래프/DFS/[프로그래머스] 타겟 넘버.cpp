#include <string>
#include <vector>

using namespace std;

vector<int> gNumbers;
int gTarget, gAnswer = 0;

void recur(int depth, int sum){
    if (depth == gNumbers.size()){
        if (sum == gTarget)
            gAnswer++;
        return ;
    }
    recur(depth+1, sum + gNumbers[depth]);
    recur(depth+1, sum - gNumbers[depth]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    gNumbers = numbers;
    gTarget = target;

    recur(0, 0);
    answer = gAnswer;

    return answer;
}