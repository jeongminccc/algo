#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    int sum = 0;
    for (int &i:d){
        sum += i;
        if (sum > budget) break;
        answer++;
    }

    return answer;
}