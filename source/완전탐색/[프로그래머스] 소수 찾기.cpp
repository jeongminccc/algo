#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX = 10000000;

bool isPrime[MAX] = {false};

void eratos(){
    for (int i=2; i<MAX; ++i)
        isPrime[i] = true;

    for (int i=2; i*i<MAX; ++i){
        if (isPrime[i]){
            for (int j=i*i; j<MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    eratos();

    string s = numbers;
    sort(s.begin(), s.end());
    do{
        for (int i=1; i<=s.size(); ++i){
            if (isPrime[stoi(s.substr(0, i))]){
                isPrime[stoi(s.substr(0, i))] = false;
                answer++;
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    return answer;
}