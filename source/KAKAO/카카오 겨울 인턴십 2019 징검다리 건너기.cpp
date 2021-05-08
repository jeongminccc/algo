#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int stoneMax = 2e8 + 1;

int solution(vector<int> stones, int k) {
    
    int lo=0, hi=stoneMax, cnt_jumps, mid;
    while (lo + 1 < hi){
        mid = (lo + hi) / 2;

        cnt_jumps = 0;
        for (int i=0; i<stones.size(); ++i){
            if (stones[i] - mid <= 0) cnt_jumps++;
            else cnt_jumps = 0;

            if (cnt_jumps >= k) break;
        }

        if (cnt_jumps >= k) hi = mid;
        else lo = mid;
    }
    return (lo + 1);
}