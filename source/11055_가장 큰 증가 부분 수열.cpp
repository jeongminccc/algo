#include <iostream>

using namespace std;

int N, dp[1001], arr[1001], ans = 0;

int main(){
	cin >> N;
	for (int i=0; i<N; ++i){
		cin >> arr[i];
		dp[i] = arr[i];
	}
		
	for (int i=0; i<N; ++i){
		for (int j=0; j<i; ++j){
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return (0);
}