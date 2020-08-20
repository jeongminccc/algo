// ConsoleApplication27.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m ,pos=0;
	vector<int> a;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a.push_back(i + 1);
		cout << a[i]; 
	}cout << "<";
	while (1) {
		pos = (pos + m - 1) % a.size();
		if (a.size() > 1) {
			cout << a[pos] << ", ";
		}
		else {
			cout << a[pos] << ">";
			break;
		}
		a.erase(a.begin() + pos);
	}
	return 0;

}