
#include "pch.h"
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
bool check[100001], finish[100001];
int a[100001];

int temp, cnt_num=0;

void dfs(int num) {
	int next;
	check[num] = true;

		next = a[num];
		if (!check[next]) {
			dfs(next);
		}
		else {
			if (!finish[next]) {
				for (int i = next; num != i; i = a[i])
					cnt_num++;
				cnt_num++;
			}
		}
		finish[num] = true;
}
int main()
{
	int n, m;

	cin >> n;
	while (n--) {
		cin >> m;
		int u, count = 0;
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
		memset(finish, false, sizeof(finish));
		for (int i = 1; i <= m; i++) {
			cin >> u;
			a[i] = u;
		}
		for (int i = 1; i <= m; i++) {
			if(check[i] == false)
			dfs(i);
		}
		cout << m - cnt_num << "\n";
		cnt_num = 0;
	}
}