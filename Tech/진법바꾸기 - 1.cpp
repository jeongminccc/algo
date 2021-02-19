#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int b;
	cin >> b;

	vector<int> v;

	while (1) {
		v.push_back(n%b);
		n /= b;
		if (n == 0) break;
	}

	vector<int>::reverse_iterator iter;
	for (iter = v.rbegin(); iter != v.rend(); iter++) {
		if (*iter >= 10) {
			char c = *iter - 10 + 'A';
			cout << c;
		}
		else {
			cout << *iter;
		}
	}
	return 0;

}