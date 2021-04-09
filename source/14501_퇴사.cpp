#include <iostream>

using namespace std;

int N, dp[20], arr[20][2];

int main(){
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i=0; i<=N; ++i){
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
    }

    cout << dp[N];
    return (0);
}