#include <iostream>
using namespace std;

long long list[10001];
long long least =0, great = 0;
long long mid, max_num=0;
int main()
{
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
		if (great <= list[i])
			great = list[i];
	}
	
	while (least<=great) {
		mid = (least + great) / 2;
		int temp = 0;

		for (int i = 0; i < n; i++) {
			if(list[i] >= mid)
			temp += list[i] - mid;
		}
		if (temp >= k) {
			if (max_num <= mid)
				max_num = mid;
			least = mid + 1;
		}
		else {
			great = mid - 1;
		}
	}

	cout << max_num;
	
	return 0;
}