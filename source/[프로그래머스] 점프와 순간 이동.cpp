#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while (n){
        if (n%2==0) n /= 2;
        else {
            n--;
            ans++;
        }
    }

    return ans;
}