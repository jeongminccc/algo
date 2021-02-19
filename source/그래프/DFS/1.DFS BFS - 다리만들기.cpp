#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, arr[111][111];
bool check[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y, int c) {
	check[x][y] = true;
	arr[x][y] = c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!check[nx][ny] && arr[nx][ny] == 1) dfs(nx, ny, c);
		}
	}
}
bool go(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] == 0) return true;
		}
	}
	return false;
}
int bfs(int x, int y, int c) {
	memset(check, 0, sizeof(check));

	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	int ret = 0;
	while (int s = q.size()) {
		while (s--) {
			int ax = q.front().first;
			int ay = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = ax + dx[i];
				int ny = ay + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (arr[nx][ny] != 0 && arr[nx][ny] != c) return ret;
					if (arr[nx][ny] == 0 && !check[nx][ny]) {
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		ret++;
	}
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	int color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !check[i][j]) dfs(i, j, color++);
		}
	}
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && go(i, j)) ans = min(ans, bfs(i, j, arr[i][j]));
		}
	}
	printf("%d\n", ans);
}