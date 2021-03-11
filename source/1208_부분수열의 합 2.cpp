#include <iostream>
#include <map>

using namespace std;

int list[41], N, S;
long long ans=0;
map<int, int> mp;

void dfsLeft(int cur, int sum)
{
	if (cur == N/2){
		mp[sum]++;
		return ;
	}
	dfsLeft(cur + 1, sum);
	dfsLeft(cur + 1, sum + list[cur]);
}

void dfsRight(int cur, int sum)
{
	if (cur == N){
		ans += mp[S - sum];
		return ;
	}
	dfsRight(cur + 1, sum);
	dfsRight(cur + 1, sum + list[cur]);
}

int main(){
	cin >> N >> S;
	for (int i=0; i<N; ++i)
		cin >> list[i];
		
	dfsLeft(0,0);
	dfsRight(N/2, 0);
	if (S == 0) ans--;
	cout << ans;
	return 0;
}