#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long cntDiffBit(long long a, long long b){
    long long ret=0;
    while (a){
        // cout << (a&1) << " " << (b&1) << endl;
        if ((a&1) != (b&1)) ret++;
        a >>= 1;
        b >>= 1;
        // cout << a << " " << ret << endl;
    }
    // cout << ret << endl;
    return (ret);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    long long tmp, tmp_ret;
    for (long long &ll:numbers){
        tmp = ll+1;
        if ((tmp_ret = cntDiffBit(tmp, ll)) > 2){
            tmp += (1 << (tmp_ret - 2)) - 1;
        }

        answer.push_back(tmp);
    }

    return answer;
}