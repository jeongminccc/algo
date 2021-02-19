#include <iostream>
#include <algorithm>
using namespace std;

int pos[200000];
int main()
{
	int n, k, start, end, mid, cnt,std, ans;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}

	sort(pos[0], pos[n - 1]);
	start = 1;
	end = pos[n - 1] - pos[0];

	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 1;
		std = pos[0];

		for (int i = 1; i < n; i++) {
			if (pos[i] - std >= mid) {
				cnt++;
				std = pos[i];
			}
		}

		if (cnt >= k) {
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
		
	}

	cout << ans;
	
	return 0;
}