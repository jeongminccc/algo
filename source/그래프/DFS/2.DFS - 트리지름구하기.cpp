#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector <pair<int, int>> tree[100100];
bool visited[100111];
int diameter = 0;
int farthestNode = 0;

void dfs(int node_num, int cost) {

	if (visited[node_num])
		return;

	visited[node_num] = true;

	if (diameter < cost) {
		diameter = cost;
		farthestNode = node_num;
	}

	for (int i = 0; i < tree[node_num].size(); i++) {
		dfs(tree[node_num][i].first, cost + tree[node_num][i].second);
	}
}



int main()
{
	int N, node;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> node;
		while (1) {
			int space, node2;
			cin >> node2;
			if (node2 == -1)
				break;
			cin >> space;
			tree[node].push_back(make_pair(node2, space));
		}
	}

	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	diameter = 0;
	dfs(farthestNode, 0);

	cout << diameter;




	return 0;
}