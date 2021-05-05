#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int is_prime[3001], cnt_prime=0;

void eratos(){
    for (int i=2; i<3001; ++i)
        is_prime[i] = true;
    
    for (int i=2; i*i<3001; ++i){
        if (is_prime[i]){
            for (int j=i*i; j<3001; j+=i)
                is_prime[j] = false;
        }
    }
}

void combi(vector<int> &nums, int sum, int pos, int depth){
    if (depth == 3){
        if (is_prime[sum]) cnt_prime++;
        return ;
    }

    for (int i=pos; i<nums.size(); ++i){
        combi(nums, sum + nums[i], i + 1, depth+1);
    }
}


int solution(vector<int> nums) {
    int answer = 0;

    eratos();

    // N개중 3개 골라서 (조합) nC3 소수인지 아닌지 판별
    // 1. 재귀함수로 직접 구현
    combi(nums, 0, 0, 0);
    answer = cnt_prime;

    // 2. next_permutation으로 구현
    vector<int> cb(nums.size(), 0);
    int sum;
    for (int i=nums.size()-3; i<nums.size(); ++i) cb[i] = 1;
    do{
        sum = 0;
        for (int i=0; i<nums.size(); ++i){
            if (cb[i]) sum += nums[i];
        }
        if (is_prime[sum]) answer++;

    } while(next_permutation(cb.begin(), cb.end()));

    return answer;
}