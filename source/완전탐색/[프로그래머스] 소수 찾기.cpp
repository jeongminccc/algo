#include <string>
#include <vector>

using namespace std;
const int MAX = 10000000;

bool isPrime[MAX] = {false};

void eratos(){
    for (int i=2; i<MAX; ++i){
        if (isPrime[i]){
            for (int j=i*i; j<MAX; j+=i){
                isPrime[i] = true;
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    eratos();

    return answer;
}