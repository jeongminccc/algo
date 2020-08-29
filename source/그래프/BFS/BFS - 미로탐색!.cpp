#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[100][100] = { 0 };
int sum_map[100][100] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<0 || nx>N - 1 || ny<0 || ny> M - 1) continue;
			if (sum_map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				sum_map[nx][ny] = sum_map[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			sum_map[i][j] = map[i][j] - '0';
		}
	}
	sum_map[0][0] = 2;
	bfs(0, 0);

	cout << sum_map[N - 1][M - 1] - 1;

	return 0;
}