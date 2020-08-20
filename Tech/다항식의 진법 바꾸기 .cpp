#include "pch.h"
#include <iostream>

using namespace std;

void go(int ten, int b) {

	if (ten == 0)
		return;
	go(ten / b, b);
	cout << (ten % b) << " ";
	return;
}

int main()
{
	int a, b, m;
	long long num[25], ten = 0;

	cin >> a >> b;

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num[i];
		long long ans = 1;
		for (int j = 0; j < m - i - 1; j++) {
			ans *= a;
		}
		ans = ans * num[i];
		ten += ans;
	}

	go(ten,b);

	return 0;
}