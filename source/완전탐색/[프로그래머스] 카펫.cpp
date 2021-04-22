#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int tmp_brown;
    for (int i=1; i<=yellow; ++i){
        if (yellow % i == 0){
            tmp_brown = i * 2; // 맨 윗줄과 아랫줄 사이의 칸
            tmp_brown += (yellow / i) * 2 + 4; // 맨 윗줄과 아랫줄

            if (tmp_brown == brown){
                answer.push_back(yellow / i + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    return answer;
}