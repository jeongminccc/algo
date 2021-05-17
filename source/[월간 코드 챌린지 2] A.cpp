#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    int sum_of_divisor, cur;
    for (int i=left; i<=right; ++i){
        sum_of_divisor = 0;
        cur = 1;
        while (cur <= i){
            if (!(i%(cur++))) sum_of_divisor++;
        }

        if (sum_of_divisor % 2) answer -= i;
        else answer += i;
    }
    return answer;
}